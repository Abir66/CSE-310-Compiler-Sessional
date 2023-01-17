%option noyywrap

%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT
%x CHARACTER_LITERAL
%x STRING_LITERAL

%{
#include<bits/stdc++.h>
#include "symbol-table/1905066_symbolTable.h"
#include "y.tab.h"

//extern YYSTYPE yylval;
extern SymbolTable *symbolTable;

extern std::ofstream logout;
extern std::ofstream errorout;
extern int line_count=1;
extern int error_count = 0;

int temp_line_count=0;


std::string comment;
std::string string_type;
std::string string_token;
std::string string_log;


// void printLog(std::string token, std::string lexeme){
// 	logout<<"Line# "<<line_count<<": Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<std::endl;
// }


// void printFunc(std::string token, std::string lexeme){
// 	printLog(token,lexeme);
// 	//printToken(token,lexeme);
// }

void generateError(std::string errorType, std::string errorLexem, int line_no = line_count){
	error_count++;
	// logout<<"Error at line# "<<line_no<<": "<<errorType<<" "<<errorLexem<<std::endl;
	// errorout<<"Error at line# "<<line_no<<": "<<errorType<<" "<<errorLexem<<std::endl;
}


%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALPHANUMERIC [a-zA-Z0-9_]
NEWLINE (\r)?\n
IDENTIFIER [a-zA-Z_]{ALPHANUMERIC}*
INTEGER {DIGIT}+
FLOAT ({DIGIT}+(\.{DIGIT}+)?|(\.{DIGIT}+))([Ee][+-]?{DIGIT}+)?|{INTEGER}\.

/* cpp allows numbers like 123.  -.-*/

%%

{WHITESPACE} { /* do nothing */ }
{NEWLINE} {line_count++;}


 /* ===================== Keywords ===================== */

"if"		{ return IF;}
"else"		{ return ELSE;}
"for"		{ return FOR;}
"while"		{ return WHILE;}
"do"		{ return DO;}
"break"		{ return BREAK;}
"int"		{ return INT;}
"char"		{ return CHAR;}
"float"		{ return FLOAT;}
"double"	{ return DOUBLE;}
"void"		{ return VOID;}
"return"	{ return RETURN;}
"switch"	{ return SWITCH;}
"case"		{ return CASE;}
"default"	{ return DEFAULT;}
"continue"	{ return CONTINUE;}
"printf"	{return PRINTLN;}



 /* ===================== Identifiers ===================== */
{IDENTIFIER}	yylval.symbolInfo = new SymbolInfo(yytext, "ID"); return ID;

 /* ===================== Numbers ===================== */
{INTEGER}		yylval.symbolInfo = new SymbolInfo(yytext, "CONST_INT"); return CONST_INT;
{FLOAT}			yylval.symbolInfo = new SymbolInfo(yytext, "CONST_FLOAT"); return CONST_FLOAT;




 /* ===================== TOO MANY DECIMAL POINTS ===================== */
(({DIGIT}+\.{DIGIT}*)|(\.{DIGIT}+))+(\.{DIGIT}*)+((([Ee][+-]?)?[\.0-9]+)?{IDENTIFIER}?)*	{generateError("TOO_MANY_DECIMAL_POINTS",yytext);}
 
 /* ===================== ILLFORMED_NUMBER ===================== */
({INTEGER}|{FLOAT})[Ee][+-]?[0-9]*\.((([Ee][+-]?)?[\.0-9]+)?{IDENTIFIER}?)* {generateError("ILLFORMED_NUMBER",yytext);}

 /* ===================== INVALID_ID_SUFFIX_NUM_PREFIX ===================== */
{INTEGER}{IDENTIFIER}|{FLOAT}{IDENTIFIER}	{generateError("INVALID_ID_SUFFIX_NUM_PREFIX",yytext);}


 /* ===================== operators ===================== */
"+"|"-"						yylval.symbolInfo = new SymbolInfo(yytext, "ADDOP"); return ADDOP;
"*"|"/"|"%"					yylval.symbolInfo = new SymbolInfo(yytext, "MULOP"); return MULOP;
"++"						return INCOP;
"--"						return DECOP;
"<"|"<="|">"|">="|"=="|"!="	yylval.symbolInfo = new SymbolInfo(yytext, "RELOP"); return RELOP;
"="							return ASSIGNOP;
"&&"|"||"					yylval.symbolInfo = new SymbolInfo(yytext, "LOGICOP"); return LOGICOP;
"&"|"|"|"^"|"<<"|">>"		yylval.symbolInfo = new SymbolInfo(yytext, "BITOP"); return BITOP;
"!"							return NOT;


 /*===================== punctuatuion ===================== */

"("		return LPAREN;
")"		return RPAREN;
"{"		return LCURL;
"}"		return RCURL;
"["		return LTHIRD;
"]"		return RTHIRD;
","		return COMMA;
";"		return SEMICOLON;



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
	//generateError("UNFINISHED_CONST_CHAR", string_log);
	line_count++;
	BEGIN INITIAL;
}

<CHARACTER_LITERAL><<EOF>>	{
	//generateError("UNFINISHED_CONST_CHAR", string_log);
	BEGIN INITIAL;
}

<CHARACTER_LITERAL>\'	{
	string_log += "'";

	if(string_token.length() == 1) {
		//printFunc("CONST_CHAR",string_token);
	}
	
	else if(string_token.length()>1) {
		//generateError("MULTICHAR_CONST_CHAR", string_log);
	}
	
	else if(string_token.length() == 0){
		if(string_log == "\\0") {
			//printFunc("CONST_CHAR",string_token);
		}
		else {
			//generateError("EMPTY_CONST_CHAR", string_log);
		}
	}

	BEGIN INITIAL;
}


 /*	This is not standard c/c++ syntax
	was not specified in the offline discription either
	Having to add this for a io provided (input3) -.-*/

<CHARACTER_LITERAL>;	{
	if(string_token.length()==0){
		string_token += yytext;
		string_log += yytext;
	}

	else {
		//generateError("UNFINISHED_CONST_CHAR", string_log);
		//printFunc("SEMICOLON",yytext);
		BEGIN INITIAL;
	}
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
								//generateError("UNFINISHED_STRING", string_log);
								line_count += temp_line_count;
								BEGIN INITIAL;
							}

<STRING_LITERAL>{NEWLINE}	{
								//generateError("UNFINISHED_STRING", string_log, line_count+temp_line_count);
								temp_line_count++;
								line_count += temp_line_count;
								BEGIN INITIAL;
							}

<STRING_LITERAL>\"	{
						string_log += "\"";
						//printLog(string_type, string_log);
						//printToken(string_type, string_token);
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
										//printLog("SINGLE LINE COMMENT",comment);
										line_count += temp_line_count;
										BEGIN INITIAL;
									}

<SINGLE_LINE_COMMENT><<EOF>>		{
										//printLog("SINGLE LINE COMMENT",comment);
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
									//printLog("MULTI LINE COMMENT",comment);
									line_count += temp_line_count;
									BEGIN INITIAL;
								}



<MULTI_LINE_COMMENT><<EOF>>		{	
									line_count += temp_line_count;
									//generateError("UNFINISHED_COMMENT", comment);
									BEGIN INITIAL;
								}

<MULTI_LINE_COMMENT>.	{ comment += yytext; }

<<EOF>>	return 0;


.	{ generateError("UNRECOGNIZED_CHAR",yytext); }

%%

