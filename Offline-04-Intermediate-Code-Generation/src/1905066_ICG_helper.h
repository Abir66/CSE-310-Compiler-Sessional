#ifndef ICG_HELPER_H
#define ICG_HELPER_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
#include"1905066_parser_helper.h"
#include"symbol-table/1905066_symbolTable.h"
#include"symbol-table/1905066_symbolInfo.h"

using namespace std;

std::ofstream codeOut;
std::ofstream tempOut;
std::ofstream optimzedCodeOut;

int label_count = 0;
int stack_offset = 0;
bool inGlobalScope = true;
extern int temp_asm_line_count = 1;
unordered_map<int, string> label_map;

// void do_backpatching(){
//     for(auto it = label_map.begin(); it != label_map.end(); it++){
//         std::cout << it->first << "-";
//         std::cout << it->second << endl;
//     }
// }



inline string new_label()
{
    return "L" + to_string(label_count++);
}

inline void backpatch(vector<int> list, string label)
{
    for(auto line : list) label_map[line] = label;
}

std::vector<int> merge(const std::vector<int> &list1, const std::vector<int> &list2)
{
    std::set<int> s(list1.begin(), list1.end());
    s.insert(list2.begin(), list2.end());
    std::vector<int> mergedList(s.begin(), s.end());
    return mergedList;
}




void genCode(string code){
    tempOut << code << endl;
    temp_asm_line_count++;
}

void genVarDeclarationCode(){
    if(!inGlobalScope){
        for(auto var : vars){
            var->setStackOffset(stack_offset+2);
            string asmName = "[BP-" + to_string(stack_offset+2) + "]";
            var->setAsmName(asmName);
            int size = max(var->getArraySize(),1) * 2;
            stack_offset += size;
            genCode("\tSUB SP, " + to_string(size));

        }
    }

    else{
        for(auto var : vars){
            var->setAsmName(var->getName());
            codeOut <<"\t" << var->getName() << " DW " << max(1,var->getArraySize()) << " DUP (0000H)" << endl; 
        }
    }
}


void genINC_DEC(SymbolInfo* var, string op){
    op = op == "++" ? "INC" : "DEC";
    if(var->isArray() && !var->isGlobalVar()) genCode("\tPOP BX");
    genCode("\tMOV AX, " + var->getAsmName());
    genCode("\tMOV AX, " + var->getAsmName());
    genCode("\tPUSH AX");
    genCode("\t" + op + " AX");
    genCode("\tMOV " + var->getAsmName() + ", AX" );
}

void genFunctioninitCode(string func_name){
    
    genCode( func_name + " PROC");
    if(func_name == "main"){
        genCode("\tMOV AX, @DATA");
        genCode("\tMOV DS, AX");
    }
    genCode("\tPUSH BP");
    genCode("\tMOV BP, SP");
}

void genFunctionEndingCode(SymbolInfo* func){
    genCode("\tADD SP, " + to_string(stack_offset));
    genCode("\tPOP BP");

    if(func->getName() == "main"){
        genCode("\tMOV AX, 4CH");
        genCode("\tINT 21H");
    }
    else{
        
        if(func->getParamCount() != 0) genCode("\tRET " + to_string(func->getParamCount()*2));
        else genCode("\tRET");
    }
    genCode(func->getName() + " ENDP");

    inGlobalScope = true;
    stack_offset = 0;
}

void asmInit(){
    codeOut << ";-------" << endl;
    codeOut << ";   " << endl;
    codeOut << ";-------" << endl;
    codeOut << ".MODEL SMALL" << endl;
    codeOut << ".STACK 1000H" << endl;
    codeOut << ".Data" << endl;
    codeOut << "\tCR EQU 0DH" << endl;
    codeOut << "\tLF EQU 0AH" << endl;
    codeOut << "\tnumber DB \"00000$\"" << endl;
}

void add_println_instructions(std::ostream &out = std::cout)
{
    ifstream file("println_instructions.txt");
    string line;
    while(getline(file, line)) out << line << endl;
    file.close();   
}

void generate_asm_file(){
    codeOut<<".CODE"<<std::endl;
    tempOut.close();
    ifstream tempFile("1905066_temp.txt");
    string line;
    int temp_asm_line_count = 1;
    while(getline(tempFile, line)) {
        codeOut << line << label_map[temp_asm_line_count] << endl;
        temp_asm_line_count++;
    }
    add_println_instructions(codeOut);
}

#endif