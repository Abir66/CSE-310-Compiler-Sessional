%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

SymbolTable *table;


void yyerror(char *s)
{
	//write your code
}

%}


%union{
    SymbolInfo* symbolInfo; 
	
}

%token  IF ELSE FOR WHILE DO BREAK RETURN SWITCH CASE DEFAULT CONTINUE  LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON PRINTLN INCOP DECOP ASSIGNOP NOT
%token<symbolInfo> ID INT FLOAT DOUBLE CONST_INT CONST_FLOAT CHAR VOID ADDOP MULOP RELOP  LOGICOP BITOP 

%type start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments



%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%


start : program;

program : program unit
	| unit
	;
unit : var_declaration
	| func_declaration
	| func_definition
	;

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
	| type_specifier ID LPAREN RPAREN SEMICOLON
	;

func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
	| type_specifier ID LPAREN RPAREN compound_statement
	;

parameter_list : parameter_list COMMA type_specifier ID
	| parameter_list COMMA type_specifier
	| type_specifier ID
	| type_specifier
	;

compound_statement : LCURL statements RCURL
	| LCURL RCURL
	;

var_declaration : type_specifier declaration_list SEMICOLON
	;

type_specifier : INT
	| FLOAT
	| VOID
	;

declaration_list : declaration_list COMMA ID
	| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
	| ID
	| ID LTHIRD CONST_INT RTHIRD
	;

statements : statement
	| statements statement
	;

statement : var_declaration
	| expression statement
	| compound_statement
	| FOR LPAREN expression_statement expression_statement expression RPAREN statement
	| IF LPAREN expression RPAREN statement
	| IF LPAREN expression RPAREN statement ELSE statement
	| WHILE LPAREN expression RPAREN statement
	| PRINTLN LPAREN ID RPAREN SEMICOLON
	| RETURN expression SEMICOLON
	;

expression_statement : SEMICOLON
	| expression SEMICOLON
	;

variable : ID
	| ID LTHIRD expression RTHIRD
	;

expression : logic_expression
	| variable ASSIGNOP logic_expression
	;

logic_expression : rel_expression
	| rel_expression LOGICOP rel_expression
	;

rel_expression : simple_expression
	| simple_expression RELOP simple_expression
	;

simple_expression : term
	| simple_expression ADDOP term
	;

term : unary_expression
	| term MULOP unary_expression
	;

unary_expression : ADDOP unary_expression
	| NOT unary_expression
	| factor
	;

factor : variable
	| ID LPAREN argument_list RPAREN
	| LPAREN expression RPAREN
	| CONST_INT { cout<<"factor - > COMST_INT"; cout<<"$1"<<endl;}
	| CONST_FLOAT
	| variable INCOP
	| variable DECOP
	;

argument_list : arguments
	|
	;

arguments : arguments COMMA logic_expression
	| logic_expression
	;

%%
int main(int argc,char *argv[])
{
	/* FILE* fp, fp2, fp3;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	fp2= fopen(argv[2],"w");
	fclose(fp2);
	fp3= fopen(argv[3],"w");
	fclose(fp3);
	
	fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a");
	

	yyin=fp; */
	yyparse();
	
/* 
	fclose(fp2);
	fclose(fp3);
	 */
	return 0;
}

