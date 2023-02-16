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

%%
