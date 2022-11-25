#include<iostream>
#include<fstream>
#include<algorithm>
#include "1905066_symbolTable.h"

void getInputString(std::ifstream &input, std::string &str)
{
    std::getline(input, str);
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

inline void printCommand(int commandCount, char cmd, std::string params, std::ofstream &output)
{
    output << "Cmd " << commandCount << ": " << cmd << " " << params << std::endl;
}

bool parameterMismatch(std::string &str, char cmd, int parameter, std::ofstream &output){
    int spaceCount = std::count(str.begin(), str.end(), ' ');
    if(spaceCount != parameter-1){
        output << "\tNumber of parameters mismatch for the command " << cmd << std::endl;
        return true;
    }
    return false;
}

int main(){


    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int bucketSize;
    char cmd;
    int commandCount = 0;
    std::string str, param1, param2;

    input >> bucketSize;

    

    while(1){
        input >> cmd;
        commandCount++;
        
        if(cmd == 'Q') break;

        if(cmd == 'I'){
            getInputString(input, str);
            printCommand(commandCount, cmd, str, output);
            if(parameterMismatch(str, cmd, 2, output)) continue;

            param1 = str.substr(0, str.find(' '));
            param2 = str.substr(str.find(' ')+1);
            
            
        }

    }


    return 0;
}