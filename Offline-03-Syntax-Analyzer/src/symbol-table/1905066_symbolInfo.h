#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <iostream>
#include <string>
#include <vector>



class SymbolInfo
{
    std::string name;
    std::string type;
    SymbolInfo *next;

    // for parse tree
    bool isTerminal = true;
    int startLine = 0, endLine = 0;
    std::vector<SymbolInfo *> children;

    // array
    bool isSymbolArray = false;
    int arraySize = 0;

public:
    // extra. will make these private and make methods later
    bool isFunc = false;
    int paramCount = 0;
    std::vector<std::pair<std::string, std::string>> params;

    bool isArr = false;

    // Constructors
    SymbolInfo() {}

    SymbolInfo(std::string name, std::string type, int startLine = 0, int endLine = 0, SymbolInfo *next = nullptr)
    {
        this->name = name;
        this->type = type;
        this->startLine = startLine;
        this->endLine = endLine;
        this->next = next;
    }

    // setters
    void setName(std::string name) { this->name = name; }
    void setType(std::string type) { this->type = type; }
    void setNext(SymbolInfo *next) { this->next = next; }
    void setArray(bool isArray = true, int arraySize = 0)
    {
        this->isSymbolArray = isSymbolArray;
        this->arraySize = arraySize;
    }
    void setArraySize(int arraySize) { this->arraySize = arraySize; }

    // getters
    std::string getName() { return name; }
    std::string getType() { return type; }
    SymbolInfo *getNext() { return next; }
    bool isArray() { return isSymbolArray; }
    int getArraySize() { return arraySize; }
    int getStartLine() { return startLine; }
    int getEndLine() { return endLine; }
    int getChildrenSize() { return children.size(); }


    // parse tree
    void addChildren(SymbolInfo *child) { 
        children.push_back(child); 
        startLine = child->startLine;
        endLine = child->endLine;
        if (children.size() > 0) isTerminal = false;
    }
    
    void addChildren(const std::vector<SymbolInfo *> &children){
        this->children.insert(this->children.end(), children.begin(), children.end());
        startLine = children[0]->startLine;
        endLine = children[children.size() - 1]->endLine;
        if (children.size() > 0) isTerminal = false;
    }

    void printParseGrammarRule(std::ostream &out){

        if(isTerminal){
            out<<type<<" : "<<name<<"\t"<<"<Line: "<<startLine<<">"<<std::endl;
            return;
        }

        out<<name<<" : ";
        for(auto child : children) {
            if(child->isTerminal) out<<child->type<<" ";
            else out<<child->name<<" ";
        }
        out<<"\t"<<"<Line: "<<startLine<<"-"<<endLine<<">"<<std::endl;
    }

    std::vector<SymbolInfo *> getChildren() { return children; }

    // print
    friend std::ostream &operator<<(std::ostream &out, SymbolInfo &symbolInfo)
    {
        out << "<" << symbolInfo.name << "," << symbolInfo.type << ">";
        return out;
    }
};

#endif