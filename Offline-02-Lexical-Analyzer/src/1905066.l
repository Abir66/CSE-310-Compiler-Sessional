%option noyywrap

%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT
%x CHARACTER_LITERAL
%x STRING_LITERAL

%{
#include<bits/stdc++.h>
#include "symbol-table/1905066_symbolTable.h"



int line_count=1;
int error_count = 0;
int temp_line_count=0;
int bucketSize=10;

std::ofstream logout;
std::ofstream tokenout;

std::string comment;
std::string string_type;
std::string string_token;
std::string string_log;

SymbolTable symbolTable(bucketSize, logout);


void printLog(std::string token, std::string lexeme){
	logout<<"Line# "<<line_count<<": Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<std::endl;
}

void printToken(std::string token, std::string lexeme){
	tokenout<<"<"<<token<<", "<<lexeme<<">"<<std::endl;	
}


void printFunc(std::string token, std::string lexeme){
	printLog(token,lexeme);
	printToken(token,lexeme);
}

void generateError(std::string errorType, std::string errorLexem, int line_no = line_count){
	error_count++;
	logout<<"Error at line# "<<line_no<<": "<<errorType<<" "<<errorLexem<<std::endl;
}


%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALPHANUMERIC [a-zA-Z0-9]
NEWLINE (\r)?\n

INTEGER {DIGIT}+
FLOAT {DIGIT}*(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?

%%

{WHITESPACE} { /* do nothing */ }
{NEWLINE} {line_count++;}


 /* ===================== Keywords ===================== */

"if"		{printFunc("IF",yytext);}
"else"		{printFunc("ELSE",yytext);}
"for"		{printFunc("FOR",yytext);}
"while"		{printFunc("WHILE",yytext);}
"do"		{printFunc("DO",yytext);}
"break"		{printFunc("BREAK",yytext);}
"int"		{printFunc("INT",yytext);}
"char"		{printFunc("CHAR",yytext);}
"float"		{printFunc("FLOAT",yytext);}
"double"	{printFunc("DOUBLE",yytext);}
"void"		{printFunc("VOID",yytext);}
"return"	{printFunc("RETURN",yytext);}
"switch"	{printFunc("SWITCH",yytext);}
"case"		{printFunc("CASE",yytext);}
"default"	{printFunc("DEFAULT",yytext);}
"continue"	{printFunc("CONTINUE",yytext);}


 /* ===================== Identifiers ===================== */

{LETTER}{ALPHANUMERIC}*		{
								printFunc("ID",yytext);
								if(symbolTable.insert(yytext, "ID")) symbolTable.printAllScopeTable();
							}

  /* ===================== Numbers ===================== */

{INTEGER}	{printFunc("CONST_INT",yytext);}
{FLOAT}		{printFunc("CONST_FLOAT",yytext);}



{DIGIT}*\.[0-9E+-]*(\.[0-9E+-]*)+	{generateError("TOO_MANY_DECIMAL_POINTS",yytext);}

 /* Jodi decimal point er por kono digit na thake OR
	Jodi decimal point er por kono digit thake but E er por kono digit na thake OR
	Jodi E er por abar E thake ba . thake taile error
 */

({DIGIT}+\.)|{DIGIT}*(\.{DIGIT}*)?E[+-]?[0-9]*[0-9\.Ee+-]* {generateError("ILLFORMED_NUMBER",yytext);}


 /* Jodi identfier er samne number thake (PS. both identifier and number has matched above. so...)*/
{DIGIT}*(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?{LETTER}{ALPHANUMERIC}*	{generateError("INVALID_ID_SUFFIX_NUM_PREFIX",yytext);}



 /* ===================== operators ===================== */
"+"|"-"						printFunc("ADDOP",yytext);
"*"|"/"|"%"					printFunc("MULOP",yytext);
"++"|"--"					printFunc("INCOP",yytext);
"<"|"<="|">"|">="|"=="|"!="	printFunc("RELOP",yytext);
"="							printFunc("ASSIGNOP",yytext);
"&&"|"||"					printFunc("LOGICOP",yytext);
"&"|"|"|"^"|"<<"|">>"		printFunc("BITOP",yytext);
"!"							printFunc("NOT",yytext);


 /*===================== punctuatuion ===================== */

"("		printFunc("LPAREN",yytext);
")"		printFunc("RPAREN",yytext);
"{"		printFunc("LCURL",yytext); symbolTable.enterScope();
"}"		printFunc("RCURL",yytext); symbolTable.exitScope();
"["		printFunc("LSQUARE",yytext);
"]"		printFunc("RSQUARE",yytext);
","		printFunc("COMMA",yytext);
";"		printFunc("SEMICOLON",yytext);



 /* ===================== character literal ===================== */

"'"		{	
			string_token = "";
			string_log = "\'";
			BEGIN CHARACTER_LITERAL;	
		}

<CHARACTER_LITERAL,STRING_LITERAL>\\\\		string_token += "\\"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\\'		string_token += "\'"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\\"		string_token += "\""; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\n		string_token += "\n"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\t      	string_token += "\t"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\a		string_token += "\a"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\b      	string_token += "\b"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\f      	string_token += "\f"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\r      	string_token += "\r"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\v      	string_token += "\v"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\0		string_token += "\0"; string_log += yytext;


<CHARACTER_LITERAL>{NEWLINE}	{
	generateError("UNFINISHED_CONST_CHAR", string_log);
	line_count++;
	BEGIN INITIAL;
}

<CHARACTER_LITERAL><<EOF>>	{
	generateError("UNFINISHED_CONST_CHAR", string_log);
	BEGIN INITIAL;
}

<CHARACTER_LITERAL>\'	{
	string_log += "'";

	if(string_token.length() == 1) printFunc("CONST_CHAR",string_token);
	
	else if(string_token.length()>1) generateError("MULTICHAR_CONST_CHAR", string_log);
	
	else if(string_token.length() == 0){
		if(string_log == "\\0") printFunc("CONST_CHAR",string_token);
		else generateError("EMPTY_CONST_CHAR", string_log);
	}

	BEGIN INITIAL;
}

<CHARACTER_LITERAL>.	string_token += yytext; string_log += yytext;



 /* ===================== string literal ===================== */

\"		{	
			string_log = "\"";
			string_token = "";
			string_type = "SINGLE LINE STRING";
			temp_line_count = 0;
			BEGIN STRING_LITERAL;	
		}


<STRING_LITERAL>\\{NEWLINE}	{
								temp_line_count++;
								string_log += "\\\n";
								string_type = "MULTI LINE STRING";
							}

<STRING_LITERAL><<EOF>>		{
								generateError("UNFINISHED_STRING", string_log);
								line_count += temp_line_count;
								BEGIN INITIAL;
							}

<STRING_LITERAL>{NEWLINE}	{
								generateError("UNFINISHED_STRING", string_log, line_count+temp_line_count);
								temp_line_count++;
								line_count += temp_line_count;
								BEGIN INITIAL;
							}

<STRING_LITERAL>\"	{
						string_log += "\"";
						printLog(string_type, string_log);
						printToken(string_type, string_token);
						line_count += temp_line_count;
						BEGIN INITIAL;
					}


<STRING_LITERAL>. {string_log += yytext; string_token += yytext;}

 /* ===================== Single line comment ===================== */
"//"	{	
			comment = "//";
			temp_line_count = 1;
			BEGIN SINGLE_LINE_COMMENT;	
		}

<SINGLE_LINE_COMMENT>\\{NEWLINE}	{
										comment += "\\\n";
										temp_line_count++;
									}

<SINGLE_LINE_COMMENT>{NEWLINE}		{
										printLog("SINGLE LINE COMMENT",comment);
										line_count += temp_line_count;
										BEGIN INITIAL;
									}

<SINGLE_LINE_COMMENT><<EOF>>		{
										printLog("SINGLE LINE COMMENT",comment);
										line_count += temp_line_count;
										BEGIN INITIAL;
									}


<SINGLE_LINE_COMMENT>.				{ comment += yytext; }



 /* ===================== Multi line comment ===================== */
"/*"	{	
			comment = "/*";
			temp_line_count = 0;
			BEGIN MULTI_LINE_COMMENT;	
		}

<MULTI_LINE_COMMENT>{NEWLINE}	{
									comment += "\n";
									temp_line_count++;
								}

<MULTI_LINE_COMMENT>"*/"		{
									comment += "*/";
									printLog("MULTI LINE COMMENT",comment);
									line_count += temp_line_count;
									BEGIN INITIAL;
								}



<MULTI_LINE_COMMENT><<EOF>>		{	
									line_count += temp_line_count;
									generateError("UNFINISHED_COMMENT", comment);
									BEGIN INITIAL;
								}

<MULTI_LINE_COMMENT>.	{ comment += yytext; }

.	{ generateError("UNRECOGNIZED_CHAR",yytext); }

%%

int main(int argc, char** argv) {
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	tokenout.open("../io/1905066_token.txt");
	logout.open("../io/1905066_log.txt");

	
	yyin= fin;
	yylex();
	fclose(yyin);

	symbolTable.printAllScopeTable();
	logout<<"Total lines: "<<line_count<<std::endl;
	logout<<"Total errors: "<<error_count<<std::endl;
	
    tokenout.close();
	logout.close();

	
    return 0;
}
