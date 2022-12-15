%option noyywrap

%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT
%x CHARACTER_LITERAL
%x STRING_LITERAL

%{
#include<bits/stdc++.h>
#include "symbol-table/1905066_symbolTable.h"



int line_count=1;
int temp_line_count=0;
int bucketSize=10;

std::ofstream logout;
std::ofstream tokenout;

std::string comment;
std::string character_literal;
std::string string_literal;

//SymbolTable st(bucketSize, logout);


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


%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALPHANUMERIC [a-zA-Z0-9]
NEWLINE (\r)?\n

%%

{WHITESPACE} { /* do nothing */ }
{NEWLINE} {line_count++;}



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



{DIGIT}+	{printFunc("CONST_INT",yytext);}
{DIGIT}*(\.{DIGIT}+)?([Ee][+-]?{DIGIT}+)?	{printFunc("CONST_FLOAT",yytext);}


{LETTER}{ALPHANUMERIC}*		{
								printFunc("ID",yytext);
								//if(st.insert(yytext, "ID")) st.printAllScopeTable();
							}

 

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
"{"		printFunc("LCURL",yytext); 
"}"		printFunc("RCURL",yytext); 
"["		printFunc("LSQUARE",yytext);
"]"		printFunc("RSQUARE",yytext);
","		printFunc("COMMA",yytext);
";"		printFunc("SEMICOLON",yytext);



 /* ===================== character literal ===================== */




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
										printFunc("COMMENT",comment);
										line_count += temp_line_count;
										BEGIN INITIAL;
									}


<SINGLE_LINE_COMMENT>.				{ comment += yytext; }



 /* ===================== Multi line comment ===================== */
"/*"	{	
			comment = "/*";
			temp_line_count = 1;
			BEGIN MULTI_LINE_COMMENT;	
		}

<MULTI_LINE_COMMENT>{NEWLINE}	{
									comment += "\n";
									temp_line_count++;
								}

<MULTI_LINE_COMMENT>"*/"		{
									comment += "*/";
									printFunc("COMMENT",comment);
									line_count += temp_line_count;
									BEGIN INITIAL;
								}

<MULTI_LINE_COMMENT>.	{ comment += yytext; }

<SINGLE_LINE_COMMENT,MULTI_LINE_COMMENT><<EOF>>	{
													printFunc("COMMENT",comment);
													line_count += temp_line_count;
													BEGIN INITIAL;
												}
		

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
	
    tokenout.close();
	logout.close();
	
    return 0;
}
