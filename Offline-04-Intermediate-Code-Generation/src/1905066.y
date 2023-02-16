%{
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"
#include"1905066_parser_helper.h"
#include"1905066_ICG_helper.h"

using namespace std;

%}


%union{
    SymbolInfo* symbolInfo; 
}

%token<symbolInfo>  IF ELSE FOR WHILE DO BREAK RETURN SWITCH CASE DEFAULT CONTINUE  LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON PRINTLN INCOP DECOP ASSIGNOP NOT
%token<symbolInfo> ID INT FLOAT DOUBLE CONST_INT CONST_FLOAT CHAR VOID ADDOP MULOP RELOP  LOGICOP BITOP 

%type<symbolInfo> variable factor term unary_expression simple_expression rel_expression logic_expression expression
%type<symbolInfo> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement argument_list arguments


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%


start : program {
		$$ = new SymbolInfo("start", "non-terminal");
		$$->addChildren($1);
		finishParsing($$);
	};

program : program unit {
		printLog("program : program unit");
		$$ = new SymbolInfo("program", "non-terminal");
		$$->addChildren({$1,$2});
	}
	| unit{
		printLog("program : unit");
		$$ = new SymbolInfo("program", "non-terminal");
		$$->addChildren($1);
	}
	;

unit : var_declaration {
		printLog("unit : var_declaration");
		$$ = new SymbolInfo("unit", "non-terminal");
		$$->addChildren($1);
	}
	| func_declaration
	{
		printLog("unit : func_declaration");
		$$ = new SymbolInfo("unit", "non-terminal");
		$$->addChildren($1);
	}
	| func_definition
	{
		printLog("unit : func_definition");
		$$ = new SymbolInfo("unit", "non-terminal");
		$$->addChildren($1);
	}
	;

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
		printLog("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		$$ = new SymbolInfo("func_declaration", "non-terminal");
		$$->setDataType($1->getDataType());

		addFunction($2, $1->getDataType());

		$$->addChildren({$1, $2, $3, $4, $5, $6});
	}
	| type_specifier ID LPAREN RPAREN SEMICOLON {
		printLog("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		$$ = new SymbolInfo("func_declaration", $1->getType());
		$$->setDataType($1->getDataType());

		addFunction($2, $1->getDataType());
		$$->addChildren({$1, $2, $3, $4, $5});
	}
	;

func_definition : type_specifier ID LPAREN parameter_list RPAREN { 
		addFunction($2, $1->getDataType(), true);
		inGlobalScope = false;
		genFunctioninitCode($2->getName());
	} compound_statement {
		printLog("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		$$ = new SymbolInfo("func_definition", "non-terminal");

		$$->addChildren({$1, $2, $3, $4, $5, $7});
		
		genFunctionEndingCode($2->getName());
		
	}
	| type_specifier ID LPAREN RPAREN { 
		addFunction($2, $1->getDataType(), true); 
		inGlobalScope = false;
		genFunctioninitCode($2->getName());
	} compound_statement {
		printLog("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		$$ = new SymbolInfo("func_definition", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $6});
		
		genFunctionEndingCode($2->getName());
	}
	;

parameter_list : parameter_list COMMA type_specifier ID {
		printLog("parameter_list : parameter_list COMMA type_specifier ID");
		$$ = new SymbolInfo("parameter_list", $1->getType());

		$4->setDataType($3->getDataType());

		if(!checkParamRedeclaration($4)) params.push_back($4);
		
		$$->addChildren({$1, $2, $3, $4});

	}
	| parameter_list COMMA type_specifier {
		printLog("parameter_list : parameter_list COMMA type_specifier");
		$$ = new SymbolInfo("parameter_list", $1->getType());

		SymbolInfo* id = new SymbolInfo("", "ID", $3->getDataType());
		params.push_back(id);

		$$->addChildren({$1, $2, $3});
	}
	| type_specifier ID {
		printLog("parameter_list : type_specifier ID");
		$$ = new SymbolInfo("parameter_list", "non-terminal");

		$2->setDataType($1->getDataType());
		if(!checkParamRedeclaration($2)) params.push_back($2);

		$$->addChildren({$1, $2});
	}
	| type_specifier {
		printLog("parameter_list : type_specifier");
		$$ = new SymbolInfo("parameter_list", "non-terminal");

		SymbolInfo* id = new SymbolInfo("", "ID", $1->getDataType());
		params.push_back(id);

		$$->addChildren($1);
	}
	;

compound_statement : LCURL {symbolTable->enterScope(); addParamsToScope();} statements RCURL {
		printLog("compound_statement : LCURL statements RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $3, $4});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
	| LCURL {symbolTable->enterScope(); addParamsToScope();} RCURL {
		printLog("compound_statement : LCURL RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $3});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();}
	;

var_declaration : type_specifier declaration_list SEMICOLON {
		printLog("var_declaration : type_specifier declaration_list SEMICOLON");
		$$ = new SymbolInfo("var_declaration", "non-terminal");
		setVarsDataType($1->getDataType());
		$$->addChildren({$1, $2, $3});

		genVarDeclarationCode();

		// insert in symbol table
		for(auto var : vars){
			bool success = symbolTable->insert(var);
			if(!success){
				std::string error_message = "Redeclaration of variable '" + var->getName() + "'";
				semanticError(var->getStartLine(), error_message);
			}

			if($1->getDataType() == "VOID"){
				std::string error_message = "Variable or field '" + var->getName() + "' declared void";
				semanticError(var->getStartLine(), error_message);
			}
		}

	}
	;

type_specifier : INT {
		printLog("type_specifier : INT");
		$$ = new SymbolInfo("type_specifier", "INT", $1->getDataType());
		$$->addChildren($1);
		
	}
	| FLOAT {
		printLog("type_specifier : FLOAT");
		$$ = new SymbolInfo("type_specifier", "FLOAT", $1->getDataType());
		$$->addChildren($1);
		
	}
	| VOID {
		printLog("type_specifier : VOID");
		$$ = new SymbolInfo("type_specifier", "VOID", $1->getDataType());
		$$->addChildren($1);
		
	}
	;

declaration_list : declaration_list COMMA ID {
		printLog("declaration_list : declaration_list COMMA ID");
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back($3);

		$$->addChildren({$1,$2,$3});
	}
	| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
		printLog("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		$3->setArray(true, std::stoi($5->getName()));
		vars.push_back($3);

		$$->addChildren({$1,$2,$3,$4,$5,$6});
	}
	| ID {
		printLog("declaration_list : ID");
		vars.clear();
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back($1);
		$$->addChildren($1);
		
	}
	| ID LTHIRD CONST_INT RTHIRD {
		printLog("declaration_list : ID LTHIRD CONST_INT RTHIRD");
		vars.clear();
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		$1->setArray(true, std::stoi($3->getName()));
		vars.push_back($1);

		$$->addChildren({$1,$2,$3,$4});
	}
	;

statements : statement {
		printLog("statements : statement");
		$$ = new SymbolInfo("statements", "non-terminal");
		$$->addChildren($1);
	}
	| statements statement {
		printLog("statements : statements statement");
		$$ = new SymbolInfo("statements", "non-terminal");
		$$->addChildren({$1, $2});
	}
	;

statement : var_declaration {
		printLog("statement : var_declaration");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren($1);
	}
	| expression_statement {
		printLog("statement : expression statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren($1);
		//------------------code generation------------------
		genCode("\tPOP AX");
	}
	| compound_statement {
		printLog("statement : compound_statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren($1);
	}
	| FOR LPAREN expression_statement expression_statement expression RPAREN statement {
		printLog("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5, $6, $7});
	}
	| IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
		printLog("statement : IF LPAREN expression RPAREN statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5});
		
	}
	| IF LPAREN expression RPAREN statement ELSE statement {
		printLog("statement : IF LPAREN expression RPAREN statement ELSE statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5, $6, $7});
	}
	| WHILE LPAREN expression RPAREN statement {
		printLog("statement : WHILE LPAREN expression RPAREN statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5});
	}
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
		printLog("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");

		// check if ID declared
		SymbolInfo *symbol = symbolTable->lookup($3->getName());
		if(!symbol) {
			std::string error_message = "Undeclared variable " + $3->getName() + " in line " + std::to_string($3->getStartLine());
			semanticError($3->getStartLine(), error_message);
		}
		else{
			genCode("\tMOV AX, " + symbol->getAsmName());
			genCode("\tCALL print_output");
			genCode("\tCALL new_line");
		}

		$$->addChildren({$1, $2, $3, $4, $5});
	}
	| RETURN expression SEMICOLON {
		printLog("statement : RETURN expression SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3});
	}
	;

expression_statement : SEMICOLON {
		printLog("expression_statement : SEMICOLON");
		$$ = new SymbolInfo("expression_statement", "non-terminal");
		$$->addChildren($1);
	}
	| expression SEMICOLON {
		printLog("expression_statement : expression SEMICOLON");
		$$ = new SymbolInfo("expression_statement", "non-terminal");
		$$->addChildren({$1, $2});
	}
	;

variable : ID {
		printLog("variable : ID");
		
		auto symbol = checkValidVar($1);
		
		if(symbol) $$ = new SymbolInfo(symbol);
		else $$ = new SymbolInfo($1);
		
		$$->setName("variable");
		$$->setType("non-terminal");

		
		if(symbol) $$->setDataType(symbol->getDataType());
		else $$->setDataType("ERROR");
		$$->addChildren($1);

		// ------------------code generation------------------
		// asmName is set in copy constructor
	}
	| ID LTHIRD expression RTHIRD {
		printLog("variable : ID LTHIRD expression RTHIRD");

		$1->setArray();

		auto symbol = checkValidVar($1, true);
		if(symbol) $$ = new SymbolInfo(symbol);
		else $$ = new SymbolInfo($1);
		
		$$->setName("variable");
		$$->setType("non-terminal");

		
		if(symbol) $$->setDataType(symbol->getDataType());
		else $$->setDataType("ERROR");
		
		if($3->getDataType() != "INT"){
			// index must be integer
			std::string error_message = "Array subscript is not an integer";
			semanticError($3->getStartLine(), error_message);
		}
		
		$$->addChildren({$1, $2, $3, $4});

		// ------------------code generation------------------
		genCode("\tPOP AX");							// get the value of index from expression(stack)
		genCode("\tSHL AX, 1"); 						// multiply by 2
		genCode("\tLEA BX, " + symbol->getAsmName()); 	// get the address of array[0]
		genCode("\tSUB BX, AX"); 						// get the address of array[index]
		genCode("\tPUSH BX"); 							// push the address of array[index] to stack
		$$->setAsmName("[BX]"); 
	}
	;

expression : logic_expression {
		printLog("expression : logic_expression");
		$$ = new SymbolInfo("expression", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| variable ASSIGNOP logic_expression {
		printLog("expression : variable ASSIGNOP logic_expression");
		$$ = new SymbolInfo("expression", "non-terminal");
		$$->setDataType($1->getDataType());

		if($3->getDataType() == "VOID"){
			// can't assign  void
			$$->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError($3->getStartLine(), error_message);
		}

		else if($1->getDataType() == "VOID"){
			// can't assign to  void
			$$->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError($1->getStartLine(), error_message);
		}

		if($1->getDataType() == "INT" && $3->getDataType() == "FLOAT"){
			std::string error_message = "Warning: possible loss of data in assignment of FLOAT to INT";
			semanticError($1->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});

		// ------------------code generation------------------
		genCode("\tPOP AX");
		genCode("\tMOV " + $1->getAsmName() + ", AX");
		if($1->isArray() && !$1->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tPUSH AX");
	}
	;

logic_expression : rel_expression {
		printLog("logic_expression : rel_expression");
		$$ = new SymbolInfo("logic_expression", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| rel_expression LOGICOP rel_expression {
		printLog("logic_expression : rel_expression LOGICOP rel_expression");
		$$ = new SymbolInfo("logic_expression", "non-terminal");
		$$->setDataType("INT");

		if($1->getDataType() == "VOID" || $3->getDataType() == "VOID"){
			$$->setDataType("VOID");
			// std::string error_message = "Can't do logic operations void";
			// semanticError($3->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});
	}
	;

rel_expression : simple_expression {
		printLog("rel_expression : simple_expression");
		$$ = new SymbolInfo("rel_expression", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| simple_expression RELOP simple_expression {
		printLog("rel_expression : simple_expression RELOP simple_expression");
		$$ = new SymbolInfo("rel_expression", "non-terminal");
		$$->setDataType("INT");

		if($1->getDataType() == "VOID" || $3->getDataType() == "VOID"){
			// can't compare void
			$$->setDataType("VOID");
			// std::string error_message = "Can't compare void";
			// semanticError($3->getStartLine(), error_message);
		}


		$$->addChildren({$1, $2, $3});
	}
	;

simple_expression : term {
		printLog("simple_expression : term");
		$$ = new SymbolInfo("simple_expression", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| simple_expression ADDOP term {
		printLog("simple_expression : simple_expression ADDOP term");
		$$ = new SymbolInfo("simple_expression", "non-terminal");
		$$->setDataType(typecast($1, $3));

		if($3->getDataType() == "VOID"){
			std::string error_message = "Can't add void";
			semanticError($3->getStartLine(), error_message);
			$$->setDataType("VOID");
		}

		$$->addChildren({$1, $2, $3});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		if($2->getName() == "+") genCode("\tADD AX, BX");
		else genCode("\tSUB AX, BX");
		genCode("\tPUSH AX");
	}
	;

term : unary_expression {
		printLog("term : unary_expression");
		$$ = new SymbolInfo("term", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| term MULOP unary_expression {
		printLog("term : term MULOP unary_expression");
		$$ = new SymbolInfo("term", "non-terminal");
		$$->setDataType(typecast($1, $3));

		if($3->getDataType() == "VOID"){
			// unary expression can't be void
			$$->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($3->getStartLine(), error_message);
		}

		if($2->getName() == "%" && ($1->getDataType() != "INT" || $3->getDataType() != "INT")){
			// not int in modulus
			$$->setDataType("INT");
			std::string error_message = "Operands of modulus must be integers ";
			semanticError($3->getStartLine(), error_message);
		}

		else if(($2->getName() == "/" || $2->getName() == "%") && $3->getValue() == "0"){
			// division by zero
			std::string error_message = "Warning: division by zero";
			semanticError($3->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});
	}
	;

unary_expression : ADDOP unary_expression {
		printLog("unary_expression : ADDOP unary_expression");
		$$ = new SymbolInfo("unary_expression", "non-terminal");
		$$->setDataType($2->getDataType());

		if($2->getDataType() == "VOID"){
			// unary expression can't be void
			$$->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2});
	}
	| NOT unary_expression {
		printLog("unary_expression : NOT unary_expression");
		$$ = new SymbolInfo("unary_expression", "non-terminal");
		$$->setDataType("INT");

		if($2->getDataType() == "VOID"){
			// unary expression can't be void
			$$->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}
		$$->addChildren({$1, $2});
	}
	| factor {
		printLog("unary_expression : factor");
		$$ = new SymbolInfo("unary_expression", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->addChildren($1);
	}
	;

factor : variable {
		printLog("factor : variable");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->setArray($1->isArray());
		$$->addChildren($1);

		// ---------------------Code generation---------------------
		genCode("\tMOV AX, " + $1->getAsmName());
		if($1->isArray() && !$1->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tPUSH AX");

	}
	| ID LPAREN argument_list RPAREN {
		printLog("factor : ID LPAREN argument_list RPAREN");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("");

		SymbolInfo *symbol= symbolTable->lookup($1->getName());

		if(!symbol){
			std::string error_message = "Undeclared function '" + $1->getName() + "'";
			semanticError($1->getStartLine(), error_message);
			$$->setDataType("ERROR");
		}
		
		else{
			
			$$->setDataType(symbol->getDataType());
			// if not function
			if(!symbol->isFunction()){
				std::string error_message = $1->getName() + " is not a function";
				semanticError($1->getStartLine(), error_message);
			}

			// else if paramater size not equal
			else if(symbol->getParamCount() > $3->getParamCount()){
				std::string error_message = "Too few arguments to function '" + $1->getName() + "'";
				semanticError($1->getStartLine(), error_message);
			}

			else if(symbol->getParamCount() < $3->getParamCount()){
				std::string error_message = "Too many arguments to function '" + $1->getName() + "'";
				semanticError($1->getStartLine(), error_message);
			}

			// else if parameter type mismatch
			else{
				vector<SymbolInfo*> params = symbol->getParams();
				vector<SymbolInfo*> args = $3->getParams();

				for(int i=0; i<params.size(); i++){

					if(params[i]->getDataType() != args[i]->getDataType()){
						
						// typecast?
						if(!(params[i]->getDataType() == "INT" || params[i]->getDataType() == "FLOAT") && (args[i]->getDataType() == "INT" || args[i]->getDataType() == "FLOAT"))
						{
							std::string error_message = "Parameter type mismatch ( For " + std::to_string(i+1) +"th parameter ) in function " + symbol->getName() + " at line " + std::to_string(symbol->getStartLine());
							semanticError($1->getStartLine(), error_message);
						}
					}
				}
			} 
		}

		if($3->getChildrenSize() == 0) $$->addChildren({$1, $2, $4});
		else $$->addChildren({$1, $2, $3, $4});
	}
	| LPAREN expression RPAREN {
		printLog("factor : LPAREN expression RPAREN");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType($2->getDataType());
		$$->addChildren({$1, $2, $3});
	}
	| CONST_INT {
		printLog("factor : CONST_INT");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("INT");
		$$->setValue($1->getName());
		$$->addChildren($1);

		// ---------------------Code generation---------------------
		genCode("\tMOV AX, " + $1->getName());
		genCode("\tPUSH AX");
	}
	| CONST_FLOAT {
		printLog("factor : CONST_FLOAT");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("FLOAT");
		$$->setValue($1->getName());
		$$->addChildren($1);
	}
	| variable INCOP {
		printLog("factor: variable INCOP");
		$$ = new SymbolInfo("factor", "non-terminal");

		if($1->isArray()){
			// array can't be incremented
			std::string error_message = "Array can't be incremented";
			semanticError($1->getStartLine(), error_message);
		}

		$$->setDataType($1->getDataType());
		$$->addChildren({$1, $2});
	}
	| variable DECOP {
		printLog("factor: variable DECOP");
		
		$$ = new SymbolInfo("factor", "non-terminal");

		if($1->isArray()){
			// array can't be decremented
			std::string error_message = "Array can't be decremented";
			semanticError($1->getStartLine(), error_message);
		}

		$$->setDataType($1->getDataType());
		$$->addChildren({$1,$2});
	}
	;

argument_list : arguments {
		printLog("argument_list : arguments");
		$$ = new SymbolInfo("argument_list", "non-terminal");
		$$->setParams($1->getParams());
		$$->addChildren($1);
	}
	| {
		printLog("argument_list : ");
		$$ = new SymbolInfo("argument_list", "non-terminal");
	}
	;

arguments : arguments COMMA logic_expression {
		printLog("arguments : arguments COMMA logic_expression");
		$$ = new SymbolInfo("arguments", "non-terminal");
		$$->setParams($1->getParams());
		$$->addParam($3);					 
		$$->addChildren({$1, $2, $3});
	}
	| logic_expression {
		printLog("arguments : logic_expression");
		$$ = new SymbolInfo("arguments", "non-terminal");
		$$->addParam($1);
		$$->addChildren($1);
	}
	;

%%
int main(int argc,char *argv[])
{
	FILE* fp;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	
	yyin=fp;
	errorOut.open("1905066_error.txt");
	logout.open("1905066_log.txt");
	parseTreeOut.open("1905066_parseTree.txt");

	codeOut.open("1905066_code.asm");
	
	yyparse();
	yylex_destroy();
	
	errorOut.close();
	logout.close();

	return 0;
}

