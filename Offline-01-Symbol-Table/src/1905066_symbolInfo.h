#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<iostream>
#include<string>


class SymbolInfo
{
    std::string name;
    std::string type;
    SymbolInfo *next;


public:

    // Constructors
    SymbolInfo(){}

    SymbolInfo(std::string name, std::string type, SymbolInfo *next = nullptr){
        this->name = name;
        this->type = type;
        this->next = next;
    }

    //setters
    void setName(std::string name){ this->name = name; }
    void setType(std::string type){ this->type = type; }
    void setNext(SymbolInfo *next){ this->next = next; }

    //getters
    std::string getName(){ return name; }
    std::string getType(){ return type; }
    SymbolInfo* getNext(){ return next; }

    //print
    friend std::ostream& operator<<(std::ostream& out, SymbolInfo& symbolInfo){
        out << "Name: " << symbolInfo.name << " Type: " << symbolInfo.type;
        return out;
    }
};



#endif