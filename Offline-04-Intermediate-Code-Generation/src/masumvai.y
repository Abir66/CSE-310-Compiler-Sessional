%{

	bool arrayIndex = false;
	map<string, string> labelMap;
	int paramCnt = 0;
	string whileLoop;
%}


%%



expression_statement : SEMICOLON {
		logRule("expression_statement : SEMICOLON",";");
		addCommentln("push 1 for infinite loop");
		genCodeln("\t\tPUSH 1\n"); 
		$$ = new SymbolInfo(";", "nonterminal");
	}			

//SymbolInfo* // variable access  // no code gen
variable : ID { 
		SymbolInfo *info = table.lookup($1->getName());
		//  check whether a variable used in an expression is declared or not
		if(info!=nullptr){
			$$ = new SymbolInfo(*info); // copy everything
			$$->setAsmName(getVarAddress(info));
			delete $1; // free ID SymbolInfo*
		}else{
			logError("Undeclared variable "+$1->getName());
			$$ = $1;
		}
	}
	| ID LTHIRD {arrayIndex = true;} expression RTHIRD {
		arrayIndex = false;
		string code = $1->getName()+"["+$4->getName()+"]";
		logRule("variable : ID LTHIRD expression RTHIRD",code);
		SymbolInfo *info = table.lookup($1->getName());
		if(info != nullptr){ // symbo found in the table
			$1->setDataType(info->getDataType());
			$1->copy(info);
			addCommentln(code);
			genCodeln("\t\tPOP AX","pop index "+$4->getName()+" of array "+$1->getName());
			genCodeln("\t\tSHL AX, 1", "multiply by 2 to get offset");
			genCodeln("\t\tLEA BX, "+info->getAsmName(), "get array base address");
			genCodeln("\t\tSUB BX, AX", "[BX]->"+code);
			genCodeln("\t\tPUSH BX\n");
			$1->setAsmName("[BX]");
		}else{
			logError("Undeclared variable "+$1->getName());
		}
		$1->setName(code);// new variable name
		$$ = $1; delete $4;
	}
	;
//SymbolInfo* //done
expression : logic_expression {
		logRule("expression : logic_expression",$1->getName());
		$$ = $1;
	}
	| variable ASSIGNOP logic_expression {
		string code = $1->getName() + "=" + $3->getName();
		logRule("expression : variable ASSIGNOP logic_expression",code);
		SymbolInfo *info = table.lookup($1->getName());
		if(info!=nullptr){
			if(info->getDataType()=="int" && $3->getDataType()=="float"){
				logError("Type mismatch");
			}
		}
		if($3->getDataType()=="void"){
				logError("Void function used in expression");
		}
		$$ = new SymbolInfo(code, "expression", $1->getType());
		// code gen
		addCommentln(code);
		genCodeln("\t\tPOP AX", "load "+$3->getName());
		genCodeln("\t\tMOV "+getVarAddress($1, true)+", AX", code);
		genCodeln("\t\tPUSH AX", "save "+$1->getName()+"\n");
		delete $1; delete $3;
	}	
	;
//SymbolInfo*
logic_expression : rel_expression { 
		logRule("logic_expression : rel_expression",$1->getName());// $$ = $1;
	}	
	| rel_expression LOGICOP {
		// short circuit
		addCommentln($1->getName()+ " short circuit jump");
		genCodeln("\t\tPOP AX", "load "+$1->getName());
		string boolVal = $2->getName() == "&&" ? "1" : "0";
		genCodeln("\t\tCMP AX, "+boolVal);
		string jmpLabel = newLabel();
		genCodeln("\t\tJNE "+jmpLabel);
		$1->setLabel(jmpLabel);
	} rel_expression {
		string code = $1->getName()+$2->getName()+$4->getName();
		logRule("logic_expression : rel_expression LOGICOP rel_expression",code);
		$$ = new SymbolInfo(code,"logic_expression","int");
		// gen code
		addCommentln(code);
		genCodeln("\t\tPOP AX", "load "+$4->getName());
		string boolVal = $2->getName() == "&&" ? "1" : "0";
		genCodeln("\t\tCMP AX, "+boolVal);
		genCodeln("\t\tJNE "+$1->getLabel());
		boolVal = $2->getName()== "&&"? "1" :"0";
		genCodeln("\t\t\tPUSH "+boolVal);
		string logicEnd = newLabel();
		genCodeln("\t\t\tJMP "+logicEnd);
		genCodeln("\t\t"+$1->getLabel()+":");
		boolVal = $2->getName()== "&&"? "0" :"1";
		genCodeln("\t\t\tPUSH " +boolVal);
		genCodeln("\t\t"+logicEnd+":\n");
		delete $1,$2,$4;
	}	
	;
//SymbolInfo*
rel_expression : simple_expression { // simple exp value is in the top of the stack
		logRule("rel_expression : simple_expression",$1->getName());
	}
	| simple_expression RELOP simple_expression	{
		string code = $1->getName()+$2->getName()+$3->getName();
		logRule("rel_expression : simple_expression RELOP simple_expression",code);
		autoTypeCasting($1,$3);
		$$ = new SymbolInfo(code,"rel_expression","int");
		string trueL = newLabel();
		string endL = newLabel();
		string op = relopToJumpIns($2->getName());
		addCommentln(code);
		genCodeln("\t\tPOP BX", "load "+$3->getName());
		genCodeln("\t\tPOP AX", "load "+$1->getName());
		genCodeln("\t\tCMP AX, BX");
		genCodeln("\t\t"+op+" "+trueL, code);
		genCodeln("\t\t\tPUSH 0\n\t\t\tJMP "+endL);
		genCodeln("\t\t"+trueL+":\n\t\t\tPUSH 1");
		genCodeln("\t\t"+endL+":\n");
		delete $1,$2,$3;
	}
	;
//SymbolInfo* // done
simple_expression : term { // term value is in the top of the stack
		logRule("simple_expression : term",$1->getName());//$$ = $1;
		//debug($1->getName()+" : "+$1->getDataType());
	}	
	| simple_expression ADDOP term {
		string code = $1->getName() + $2->getName()  + $3->getName();
		logRule("simple_expression : simple_expression ADDOP term",code);
		checkVoidFunction($1, $3);
		$$ = new SymbolInfo(code, "simple_expression", autoTypeCasting($1, $3));
		// code gen
		addCommentln($1->getName()+$2->getName()+$3->getName());
		genCodeln("\t\tPOP BX", "load "+$3->getName());
		genCodeln("\t\tPOP AX", "load "+$1->getName());
		string op = $2->getName() == "+" ? "ADD" : "SUB";
		genCodeln("\t\t"+op+" AX, BX");
		genCodeln("\t\tPUSH AX", "save "+$1->getName()+"\n");
		delete $1; delete $2; delete $3;
	} 
	;
//SymbolInfo*
term :	unary_expression { // no code: unary_expression value is in the top of the stack
		logRule("term : unary_expression",$1->getName()); //$$ = $1; 
	}
    |  term MULOP unary_expression {
		string code = $1->getName() + $2->getName()  + $3->getName();
		logRule("term : term MULOP unary_expression",code);
		checkVoidFunction($1, $3);
		if($2->getName() == "%"){
			if($3->getName() == "0") logError("Modulus by Zero");
			// Type Checking: Both the operands of the modulus operator should be integers.
			if($1->getDataType() != "int" || $3->getDataType() != "int"){
				logError("Non-Integer operand on modulus operator");
			}
			$1->setDataType("int");
			$3->setDataType("int");
		}
		// gen code
		addCommentln(code);
		genCodeln("\t\tPOP BX", "load "+$3->getName());
		genCodeln("\t\tPOP AX", "load "+$1->getName());
		genCodeln("\t\tXOR DX, DX", "clear DX");
		string op = $2->getName() == "*" ? "IMUL" : "IDIV";
		genCodeln("\t\t"+op+" BX", code);
		string result = $2->getName() == "%" ? "DX" : "AX";
		genCodeln("\t\tPUSH "+result, "save "+code+"\n");
		$$ = new SymbolInfo(code, "term", autoTypeCasting($1,$3));
		delete $1; delete $2; delete $3;
	}
    ;
//SymbolInfo* 
unary_expression : ADDOP unary_expression {
		string code = $1->getName() + $2->getName();
		logRule("unary_expression : ADDOP unary_expression",code);
		$$ = new SymbolInfo(code, "unary_expression", $2->getDataType());
		if($1->getName() == "-"){
			addCommentln("-"+$2->getName());
			genCodeln("\t\tPOP AX");
			genCodeln("\t\tNEG AX");
			genCodeln("\t\tPUSH AX\n");
		}
		delete $1; delete $2;
	}  
	| NOT unary_expression {
		string code = "!"+ $2->getName();
		logRule("unary_expression : NOT unary_expression",code);
		$$ = new SymbolInfo(code, "unary_expression", $2->getDataType());
		
		string l1 = newLabel();
		string l2 = newLabel(); 
		addCommentln("!"+$2->getName());
		genCodeln("\t\tPOP AX\t\t;load "+$2->getName());
		genCodeln("\t\tCMP AX, 0");
		genCodeln("\t\tJE "+l1);
		genCodeln("\t\t\tPUSH 0");
		genCodeln("\t\t\tJMP "+l2);
		genCodeln("\t\t"+l1+":\n\t\tPUSH 1\n");
		genCodeln("\t\t"+l2+":");
		
		delete $2;
	} 
	| factor {
		logRule("unary_expression : factor",$1->getName());
	} 
	;
	
//SymbolInfo*
factor	: variable {
		logRule("factor : variable",$1->getName());
		genCodeln("\t\tPUSH "+getVarAddress($1, true), "save "+$1->getName()+"\n");
		$$ = $1;
	}
	| ID LPAREN {
		addCommentln("calling function "+$1->getName());
	} argument_list RPAREN { // function call
		string code = $1->getName() + "(" + toSymbolNameListStr($4) + ")";
		logRule("factor : ID LPAREN argument_list RPAREN",code);
		callFunction($1,$4);
		$$ = new SymbolInfo(code, "function", $1->getReturnType());
		//debug($$->getName()+" : "+$$->getDataType());
		genCodeln("\t\tPUSH 0", "location for return value"); // BP+4
		genCodeln("\t\tCALL "+$1->getName(), "call function"+$1->getName());
		genCodeln("\t\tPOP AX", "load return value");
		genCodeln("\t\tADD SP,"+to_string($4->size()*2), "pop function param from stack");
		if($1->getReturnType() != "void"){
			genCodeln("\t\tPUSH AX", "save return value");
		}else{
			genCodeln("\t\tPUSH 0", "save dummy return value for void");
		}
		addCommentln("returned from function "+$1->getName()+"\n");
		delete $1; freeSymbolInfoVector($4);
	}
	| LPAREN expression RPAREN {
		string code = "(" + $2->getName() + ")";
		logRule("factor : LPAREN expression RPAREN",code);
		$$ = new SymbolInfo(code, "factor", $2->getDataType());
		delete $2;
	}
	| CONST_INT { // terminal
		logRule("factor : CONST_INT", $1->getName());
		genCodeln("\t\tPUSH " + $1->getName(), "save "+$1->getName()+"\n");
		$$ = new SymbolInfo($1->getName(), $1->getType(), "int");
	}
	| CONST_FLOAT { // terminal
		logRule("factor : CONST_FLOAT",$1->getName());
		genCodeln("\t\tPUSH " + $1->getName(), "save "+$1->getName()+"\n");
		$$ = new SymbolInfo($1->getName(), "factor", "float");
	}
	| variable INCOP {
		string code = $1->getName() + "++";
		logRule("factor : variable INCOP",code);
		genUnaryOerationCode($1);
		$$ = new SymbolInfo(code, "factor", $1->getDataType());
		delete $1;
	}
	| variable DECOP {
		string code = $1->getName() + "--";
		logRule("factor : variable DECOP",code);
		genUnaryOerationCode($1, false);
		$$ = new SymbolInfo(code, "factor", $1->getDataType());
		delete $1;
	}
	;
	

%%
