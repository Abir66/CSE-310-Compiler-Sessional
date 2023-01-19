%{
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void); 
int yylex(void);
extern FILE *yyin;
extern int yylineno;
extern int line_count;
extern int error_count;


//io
std::ofstream logout;
std::ofstream errorOut;
std::ofstream parseTreeOut;


SymbolTable *symbolTable = new SymbolTable(11, logout);

std::vector<SymbolInfo*> vars, params;
SymbolInfo* currentFunction = NULL;


void yyerror(char *s)
{
	logout<<"Error at line no "<<yylineno<<": "<<s<<endl;
	error_count++;
}


void printLog(std::string str){
	logout<<str<<std::endl;
}

void semanticError(int lineno, std::string error_text){
	errorOut<<"Line# "<<lineno<<": "<<error_text<<std::endl;
	error_count++;
}


void printParseTree(SymbolInfo* symbol, int indent){
	// print indent number of spaces
	for(int i = 0; i < indent; i++) parseTreeOut<<" ";

	// print the symbol
	symbol->printParseGrammarRule(parseTreeOut);

	// print the children
	for(auto child : symbol->getChildren()) printParseTree(child, indent + 1);

	// delete the symbol
	if(symbol) delete symbol;
}

void setVarsDataType(std::string dataType){
	for(auto var : vars) var->setDataType(dataType);
}


void addFunction(SymbolInfo* function, std::string returnType, bool define = false){

	function->setDataType(returnType);
	function->addParams(params);
	function->setFuncDeclared();

	if(define){
		
		function->setFuncDefined(function->getStartLine());
		
		for(auto param : params){
			if(param->getName() == ""){
				// unnamed parameter error
				std::string error = "Unnamed parameter at line " + std::to_string(param->getStartLine());
				semanticError(param->getStartLine(), error);
			}
		}
	}
	
	params.clear();
	
	bool success = symbolTable->insert(function);
	//addParamsToScope();

	if(success) {
		currentFunction = function;
		return;
	} 
	

	SymbolInfo* existingFunction = symbolTable->lookup(function->getName());


	if(!existingFunction->isFunction()){
		// already a declared variable error
		std::string error = "'" + function->getName() + "' redeclared as different kind of symbol (" + std::to_string(existingFunction->getStartLine()) + ")";
		semanticError(function->getStartLine(), error);
		return;
	}

	else if(existingFunction->isFuncDefined()){
		// function already defined error
		std::string error = "Function '" + function->getName() + "' already defined at line " + std::to_string(existingFunction->getDefinedLine());
		semanticError(function->getStartLine(), error);
	}

	else if(existingFunction->isFuncDeclared() && !define) {
		// multiple declaration error
		std::string error = "Function '" + function->getName() + "' already declared at line " + std::to_string(existingFunction->getStartLine());
		semanticError(function->getStartLine(), error);
	}

	else if(existingFunction->isFuncDeclared() && define){
		

		if(existingFunction->getDataType() != returnType){
			// return type mismatch error
			std::string error = "Return type mismatch with function declaration at line " + std::to_string(existingFunction->getStartLine());
			semanticError(function->getStartLine(), error);
		}

		else if(existingFunction->getParamCount() != function->getParamCount()){
			// parameter count mismatch error
			std::string error = "Parameter count mismatch with function declaration at line " + std::to_string(existingFunction->getStartLine());
			semanticError(function->getStartLine(), error);
		}

		else {

			auto existingParams = existingFunction->getParams();
			auto newParams = function->getParams();

			for(int i = 0; i < existingParams.size(); i++){
				if(existingParams[i]->getDataType() != newParams[i]->getDataType()){
					// parameter type mismatch error
					std::string error = "Parameter type mismatch (for parameter : " + existingParams[i]->getName() + ") with function declaration at line " + std::to_string(existingFunction->getStartLine());
					semanticError(function->getStartLine(), error);
				}
			}

			//existingFunction->setDefined();
			existingFunction->setParams(newParams);
			currentFunction = function;
		}
	}

	if(define && existingFunction->isFunction()) existingFunction->setFuncDefined(function->getStartLine());

}

bool checkParamRedeclaration(SymbolInfo* newParam){
	for(auto param : params){
		if(param->getName() == newParam->getName()){
			// parameter redeclaration error
			std::string error = "Redefinition of parameter '" + newParam->getName() + "'";
			semanticError(newParam->getStartLine(), error);
			return true;
		}
	}
	return false;
}

void addParamsToScope(){
	if(currentFunction == NULL) return;
	for(auto param : currentFunction->getParams()) symbolTable->insert(param);
	currentFunction = NULL;
}

void checkValidVar(SymbolInfo* id, bool isArray = false){
	
	auto var = symbolTable->lookup(id->getName());

	if(!var){
		// undeclared variable error
		std::string error = "Undeclared variable '" + id->getName() + "'";
		semanticError(id->getStartLine(), error);
	}

	else if(isArray && !var->isArray()){
		// array
		std::string error = "'" + id->getName() + "' is not an array";
		semanticError(id->getStartLine(), error);
	}

	else if(!isArray && var->isArray()){
		// array
		std::string error = "Array '" + id->getName() + "' used as a variable at line " + std::to_string(id->getStartLine());
		semanticError(id->getStartLine(), error); 
	}

	else if(var->isFunction()){
		// function call error
		std::string error = "Function '" + id->getName() + "' used as a variable at line " + std::to_string(id->getStartLine());
		semanticError(id->getStartLine(), error);
	}
}

std::string typecast(SymbolInfo *left_symbol, SymbolInfo *right_symbol){
	if(left_symbol->getDataType() == "VOID" || right_symbol->getDataType() == "VOID") return "VOID"; // error
	else if(left_symbol->getDataType() == "DOUBLE" || right_symbol->getDataType() == "DOUBLE") return "DOUBLE";
	else if(left_symbol->getDataType() == "FLOAT" || right_symbol->getDataType() == "FLOAT") return "FLOAT";
	else return "INT";
}



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
		printLog("start : program");
		logout<<"Total Lines: "<<line_count<<std::endl;
		logout<<"Total Errors: "<<error_count<<std::endl;

		$$ = new SymbolInfo("start", "non-terminal");
		$$->addChildren($1);
		printParseTree($$, 0);
		delete symbolTable;
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
		printLog("func_declaration : type_specifier");
		$$ = new SymbolInfo("func_declaration", $1->getType());
		$$->setDataType($1->getDataType());

		addFunction($2, $1->getDataType());
		$$->addChildren({$1, $2, $3, $4, $5});
	}
	;

func_definition : type_specifier ID LPAREN parameter_list RPAREN { addFunction($2, $1->getDataType(), true); addParamsToScope();} compound_statement {
		printLog("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		$$ = new SymbolInfo("func_definition", "non-terminal");

		$$->addChildren({$1, $2, $3, $4, $5, $7});
	}
	| type_specifier ID LPAREN RPAREN { addFunction($2, $1->getDataType(), true); } compound_statement {
		printLog("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		$$ = new SymbolInfo("func_definition", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $6});
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

compound_statement : LCURL {symbolTable->enterScope();} statements RCURL {
		printLog("compound_statement : LCURL statements RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $3, $4});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
	| LCURL {symbolTable->enterScope();} RCURL {
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

		// insert in symbol table
		for(auto var : vars){
			bool success = symbolTable->insert(var);
			if(!success){
				std::string error_message = "Redeclaration of variable " + var->getName() + " in line " + std::to_string(var->getStartLine());
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
		if(symbol) {
			std::string error_message = "Undeclared variable " + $3->getName() + " in line " + std::to_string($3->getStartLine());
			semanticError($3->getStartLine(), error_message);
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
		printLog("varibale : ID");

		$$ = new SymbolInfo($1);
		$$->setName("variable");
		$$->setType("non-terminal");

		checkValidVar($1);
		$$->setDataType($1->getDataType());
		
		$$->addChildren($1);
	}
	| ID LTHIRD expression RTHIRD {
		printLog("variable : ID LTHIRD expression RTHIRD");
		$1->setArray();
		
		$$ = new SymbolInfo($1);
		$$->setName("variable");
		$$->setType("non-terminal");

		checkValidVar($1, true);
		$$->setDataType($1->getDataType());
		
		if($3->getDataType() != "INT"){
			// index must be integer
			std::string error_message = "Array subscript is not an integer";
			semanticError($3->getStartLine(), error_message);
		}
		
		$$->addChildren({$1, $2, $3, $4});
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
			std::string error_message = "Void cannot be used in expression";
			semanticError($3->getStartLine(), error_message);
		}

		else if($1->getDataType() == "VOID"){
			// can't assign to  void
			$$->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression";
			semanticError($1->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});
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
			// std::string error_message = "Can't add void";
			// semanticError($3->getStartLine(), error_message);
			$$->setDataType("VOID");

		}

		$$->addChildren({$1, $2, $3});
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
			$$->setDataType("ERROR");
			std::string error_message = "Operands of modulus must be integers";
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
		$$->addChildren($1);
	}
	;

factor : variable {
		printLog("factor: variable");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->setArray($1->isArray());
		$$->addChildren($1);
	}
	| ID LPAREN argument_list RPAREN {
		printLog("factor: ID LPAREN argument_list RPAREN");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("");

		SymbolInfo *symbol= symbolTable->lookup($1->getName());

		if(!symbol){
			std::string error_message = "Undeclared function '" + $1->getName() + "'";
			semanticError($1->getStartLine(), error_message);
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

		
		$$->addChildren({$1, $2, $3, $4});
	}
	| LPAREN expression RPAREN {
		printLog("factor: LPAREN expression RPAREN");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType($2->getDataType());
		$$->addChildren({$1, $2, $3});
	}
	| CONST_INT {
		printLog("factor: CONST_INT");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("INT");
		$$->addChildren($1);
	}
	| CONST_FLOAT {
		printLog("factor: CONST_FLOAT");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("FLOAT");
		$$->addChildren($1);
	}
	| variable INCOP {
		printLog("factor: variable INCOP");
		std::cout<<"variable INCOP"<<std::endl;
		std::cout<<$1->getName()<<std::endl;
		std::cout<<$1->getStartLine()<<std::endl;
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
	FILE* fp, fp2, fp3;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	/* fp2= fopen(argv[2],"w");
	fclose(fp2);
	fp3= fopen(argv[3],"w");
	fclose(fp3);
	
	fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a"); */
	

	yyin=fp;
	errorOut.open("1905066_error.txt");
	logout.open("1905066_log.txt");
	parseTreeOut.open("1905066_parseTree.txt");
	/* std::cout<<"okay"<<std::endl; */
	yyparse();
	
	errorOut.close();
	logout.close();
/* 
	fclose(fp2);
	fclose(fp3);
	 */
	return 0;
}

