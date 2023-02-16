#ifndef ICG_HELPER_H
#define ICG_HELPER_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"1905066_parser_helper.h"

using namespace std;

std::ofstream codeOut;
std::ofstream tempOut;
std::ofstream optimzedCodeOut;


int label_count = 0;
int stack_offset = 0;
bool inGlobalScope = true;



inline string new_label()
{
    return "L" + to_string(label_count++);
}


void println_instructions(std::ostream &out = std::cout)
{
    ifstream file("println_instructions.txt");
    string line;
    while(getline(file, line)) out << line << endl;   
}

void genCode(string code){
    codeOut << code << endl;
}

void genVarDeclarationCode(){
    if(!inGlobalScope){
        for(auto var : vars){
            var->setStackOffset(stack_offset+2);
            string asmName = "[BP-" + to_string(stack_offset+2) + "]";
            var->setAsmName(asmName);
            int size = max(var->getArraySize(),1) * 2;
            stack_offset += size;
            codeOut << "\tSUB SP, " << size << endl;
        }
    }
}

void getVarAddress(){
    
}


void genFunctioninitCode(string func_name){
    
    codeOut << func_name << " PROC" << endl;
    if(func_name == "main"){
        codeOut << "\tMOV AX, @DATA" << endl;
        codeOut << "\tMOV DS, AX" << endl;
    }
    codeOut << "\tPUSH BP" << endl;
    codeOut << "\tMOV BP, SP" << endl;
}

void genFunctionEndingCode(string func_name){
    codeOut<<"\tADD SP, "<<stack_offset<<endl;
    codeOut<<"\tPOP BP"<<endl;

    if(func_name == "main"){
        codeOut << "\tMOV AX, 4CH" << endl;
        codeOut << "\tINT 21H" << endl;
    }
    codeOut << func_name << " ENDP" << endl;

    inGlobalScope = true;
    stack_offset = 0;
}




#endif