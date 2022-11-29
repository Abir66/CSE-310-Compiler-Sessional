#include<iostream>
#include<fstream>
#include<algorithm>
#include "1905066_symbolTable.h"

void getCommand(std::string &str, char &cmd, int &commandCount)
{
    std::getline(std::cin, str);
    commandCount++;
    std::cout << "Cmd " << commandCount << ": " << str << std::endl;
    
    cmd = str[0];

    if(str.size()>2){
        str.erase(0, str.find_first_not_of(' ', 1));
        str.erase(str.find_last_not_of(' ') + 1);
    }
    else str = "";
}

bool parameterMismatch(std::string &str, char cmd, int parameter){

    
    int wordCount = 1;
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' ' && str[i+1] != ' ') wordCount++;
    }

    if(wordCount != parameter || (str.size() == 0 && parameter != 0)){
        std::cout << "\tNumber of parameters mismatch for the command " << cmd << std::endl;
        return true;
    }
    return false;
}


int main(){

    // io
    freopen("../io/1905066_input.txt", "r", stdin);
    freopen("../io/1905066_output.txt", "w", stdout);

    int bucketSize;
    char cmd;
    int commandCount = 0;
    std::string str, param1, param2;

    std::cin >> bucketSize;
    std::getchar(); // garbadge newline character because std::getline in the loop ¯\_(ツ)_/¯

    SymbolTable symbolTable(bucketSize);

    while(1){
        getCommand(str, cmd, commandCount);
        
        if(cmd == 'Q') {
            break;
        }

        if(cmd == 'I'){
            if(parameterMismatch(str, cmd, 2)) continue;

            param1 = str.substr(0, str.find(' '));
            param2 = str.substr(str.find(' ')+1);

            symbolTable.insert(param1, param2);   
        }

        else if(cmd == 'L'){
            if(parameterMismatch(str, cmd, 1)) continue;

            symbolTable.lookup(str);
        }

        else if(cmd == 'D'){
            if(parameterMismatch(str, cmd, 1)) continue;
            
            symbolTable.remove(str);
        }

        else if(cmd == 'P'){
            if(parameterMismatch(str, cmd, 1)) continue;

            if(str == "C") symbolTable.printCurrentScopeTable();
            else if(str == "A") symbolTable.printAllScopeTable();
            // else output << "\tInvalid parameter for command " << cmd << std::endl;
        }

        else if(cmd == 'S'){
            symbolTable.enterScope();
        }

        else if(cmd == 'E'){
            symbolTable.exitScope();
        }

        else{
            //std::cout << "\tInvalid command " << cmd << std::endl;
        }


    }


    return 0;
}