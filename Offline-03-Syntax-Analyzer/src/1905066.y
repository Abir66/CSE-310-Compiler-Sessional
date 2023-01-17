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


void yyerror(char *s)
{
	//write your code
}


void printLog(std::string str){
	logout<<str<<std::endl;
}


inline void safeDelete(SymbolInfo* pointer){
	if (pointer != NULL) delete pointer;
}

inline void safeDelete(std::vector<SymbolInfo*> pointers){
	for(auto pointer : pointers) if (pointer != NULL) delete pointer;
}

void generateError(std::string logoutError, std::string erroroutError){

}

void printParseTree(SymbolInfo* symbol, int indent){
	// print indent number of spaces
	for(int i = 0; i < indent; i++) parseTreeOut<<" ";

	// print the symbol
	symbol->printParseGrammarRule(parseTreeOut);

	// print the children
	for(auto child : symbol->getChildren()) printParseTree(child, indent + 1);

	// delete the symbol
	safeDelete(symbol);
}

void setVarsDataType(std::string dataType){
	for(auto var : vars)
		var->setDataType(dataType);
}


void addFunction(SymbolInfo* function, std::string returnType, bool define = false){
	
	function->setDataType(returnType);
	function->addParams(params);
	function->setFuncDeclared();
	if(define) function->setFuncDefined();
	
	params.clear();
	
	bool success = symbolTable->insert(function);
	if(success) return;

	SymbolInfo* existingFunction = symbolTable->lookup(function->getName());

	if(!existingFunction->isFunction()){
		// error
		return;
	}

	else if(existingFunction->isFuncDefined()){
		// function already defined error
	}

	else if(existingFunction->isFuncDeclared() && !define) {
		// multiple declaration error
	}

	else if(existingFunction->isFuncDeclared() && define){
		

		if(existingFunction->getDataType() != returnType){
			// return type mismatch error
		}

		else if(existingFunction->getParamCount() != function->getParamCount()){
			// parameter mismatch error
		}

		else {

			auto existingParams = existingFunction->getParams();
			auto newParams = function->getParams();

			for(int i = 0; i < existingParams.size(); i++){
				if(existingParams[i]->getDataType() != newParams[i]->getDataType()){
					// parameter type mismatch error
				}
			}

			//existingFunction->setDefined();
			existingFunction->setParams(newParams);
		}
	}
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

func_definition : type_specifier ID LPAREN parameter_list RPAREN { addFunction($2, $1->getDataType(), true); } compound_statement {
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
		params.push_back($4);

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
		params.push_back($2);

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

compound_statement : LCURL statements RCURL {
		printLog("compound_statement : LCURL statements RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $2, $3});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
	| LCURL RCURL {
		printLog("compound_statement : LCURL RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $2});
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
				// error_count++;
				// logout<<"Error at line "<<line_count<<": Redeclaration of variable "<<var->getName()<<std::endl;
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
		printLog("statements statement");
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
		$$ = new SymbolInfo("variable", $1->getType());
		$$->addChildren($1);
	}
	| ID LTHIRD expression RTHIRD {
		printLog("variable : ID LTHIRD expression RTHIRD");
		$$ = new SymbolInfo("variable", $1->getType());
		$1->setArray();
		$$->setArray(); // do i need to?
		$$->addChildren({$1, $2, $3, $4});
	}
	;

expression : logic_expression {
		printLog("expression : logic_expression");
		$$ = new SymbolInfo("expression", "INT");
		$$->addChildren($1);
	}
	| variable ASSIGNOP logic_expression {printLog("expression : variable ASSIGNOP logic_expression");
		$$ = new SymbolInfo("expression", "INT");
		$$->addChildren({$1, $2, $3});
	}
	;

logic_expression : rel_expression {
		printLog("logic_expression : rel_expression");
		$$ = new SymbolInfo("logic_expression", "INT");
		$$->addChildren($1);
	}
	| rel_expression LOGICOP rel_expression {
		printLog("logic_expression : rel_expression LOGICOP rel_expression");
		$$ = new SymbolInfo("logic_expression", "INT");
		$$->addChildren({$1, $2, $3});
	}
	;

rel_expression : simple_expression {
		printLog("rel_expression : simple_expression");
		$$ = new SymbolInfo("rel_expression", "INT");
		$$->addChildren($1);
	}
	| simple_expression RELOP simple_expression {
		printLog("rel_expression : simple_expression RELOP simple_expression");
		$$ = new SymbolInfo("rel_expression", "INT");
		$$->addChildren({$1, $2, $3});
	}
	;

simple_expression : term {
		printLog("simple_expression : term");
		$$ = new SymbolInfo("simple_expression", "INT");
		$$->addChildren($1);
	}
	| simple_expression ADDOP term {
		printLog("simple_expression : simple_expression ADDOP term");
		$$ = new SymbolInfo("simple_expression", "INT");
		$$->addChildren({$1, $2, $3});
	}
	;

term : unary_expression {
		printLog("term : unary_expression");
		$$ = new SymbolInfo("term", "INT");
		$$->addChildren($1);
	}
	| term MULOP unary_expression {
		printLog("term : term MULOP unary_expression");
		$$ = new SymbolInfo("term", "INT");
		$$->addChildren({$1, $2, $3});
	}
	;

unary_expression : ADDOP unary_expression {
		printLog("unary_expression : ADDOP unary_expression");
		$$ = new SymbolInfo("unary_expression", "INT");
		$$->addChildren({$1, $2});
	}
	| NOT unary_expression {
		printLog("unary_expression : NOT unary_expression");
		$$ = new SymbolInfo("unary_expression", "INT");
		$$->addChildren({$1, $2});
	}
	| factor {
		printLog("unary_expression : factor");
		$$ = new SymbolInfo("unary_expression", "INT");
		$$->addChildren($1);
	}
	;

factor : variable {
		printLog("factor: variable");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren($1);
	}
	| ID LPAREN argument_list RPAREN {
		printLog("factor: ID LPAREN argument_list RPAREN");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren({$1, $2, $3, $4});
	}
	| LPAREN expression RPAREN {
		printLog("factor: LPAREN expression RPAREN");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren({$1, $2, $3});
	}
	| CONST_INT {
		printLog("factor: CONST_INT");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren($1);
	}
	| CONST_FLOAT {
		printLog("factor: CONST_FLOAT");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren($1);
	}
	| variable INCOP {
		printLog("factor: variable INCOP");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren($1);
	}
	| variable DECOP {
		printLog("factor: variable DECOP");
		$$ = new SymbolInfo("factor", "INT");
		$$->addChildren($1);
	}
	;

argument_list : arguments {
		printLog("argument_list : arguments");
		$$ = new SymbolInfo("argument_list", "non-terminal");
		$$->addChildren($1);
	}
	| %empty {
		printLog("argument_list : ");
		$$ = new SymbolInfo("argument_list", "non-terminal");
	}
	;

arguments : arguments COMMA logic_expression {
		printLog("arguments : arguments COMMA logic_expression");
		$$ = new SymbolInfo("arguments", "non-terminal");
		$$->addChildren({$1, $2, $3});
	}
	| logic_expression {
		printLog("arguments : logic_expression");
		$$ = new SymbolInfo("arguments", "non-terminal");
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
	std::cout<<"okay"<<std::endl;
	yyparse();
	
	errorOut.close();
	logout.close();
/* 
	fclose(fp2);
	fclose(fp3);
	 */
	return 0;
}

