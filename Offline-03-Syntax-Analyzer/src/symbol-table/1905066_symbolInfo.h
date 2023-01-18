#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <iostream>
#include <string>
#include <vector>



class SymbolInfo
{
    std::string name;
    std::string type;
    std::string dataType;
    SymbolInfo *next;

    // for parse tree
    bool isTerminal = true;
    int startLine = 0;
    int endLine = 0;
    std::vector<SymbolInfo *> children;

    // array
    bool isSymbolArray = false;
    int arraySize = 0;

    // for function
    bool funcDeclared = false;
    bool funcDefined = false;
    int definedLine = 0;
    std::vector<SymbolInfo *> params;

public:

    // ====================== Constructors ======================
    SymbolInfo() {}

    SymbolInfo(std::string name, std::string type, int startLine = 0, int endLine = 0, SymbolInfo *next = nullptr)
    {
        this->name = name;
        this->type = type;
        this->startLine = startLine;
        this->endLine = endLine;
        this->next = next;
    }

    SymbolInfo(std::string name, std::string type, std::string dataType, int startLine = 0, int endLine = 0, SymbolInfo *next = nullptr)
    {
        this->name = name;
        this->type = type;
        this->startLine = startLine;
        this->endLine = endLine;
        this->next = next;
        this->dataType = dataType;
    }

    SymbolInfo(SymbolInfo *symbolInfo){
        this->name = symbolInfo->name;
        this->type = symbolInfo->type;
        this->next = symbolInfo->next;
        this->dataType = symbolInfo->dataType;

        this->startLine = symbolInfo->startLine;
        this->endLine = symbolInfo->endLine;
        this->isTerminal = symbolInfo->isTerminal;
        this->children = symbolInfo->children;

        this->funcDeclared = symbolInfo->funcDeclared;
        this->funcDefined = symbolInfo->funcDefined;
        this->params = symbolInfo->params;

        this->isSymbolArray = symbolInfo->isSymbolArray;
        this->arraySize = symbolInfo->arraySize;
        
    }

    // ====================== Setters and Getters ======================
    void setName(std::string name) { this->name = name; }
    void setType(std::string type) { this->type = type; }
    void setNext(SymbolInfo *next) { this->next = next; }
    void setStartLine(int startLine) { this->startLine = startLine; }
    void setEndLine(int endLine) { this->endLine = endLine; }
    void setDataType(std::string dataType) { this->dataType = dataType; }
    
    std::string getName() { return name; }
    std::string getType() { return type; }
    SymbolInfo *getNext() { return next; }
    int getStartLine() { return startLine; }
    int getEndLine() { return endLine; }
    std::string getDataType() { return dataType; }
    
    

    // ====================== For Array ======================
    void setArray(bool isSymbolArray = true, int arraySize = 0)
    {
        this->isSymbolArray = isSymbolArray;
        this->arraySize = arraySize;
    }
    void setArraySize(int arraySize) { this->arraySize = arraySize; }
    bool isArray() { return isSymbolArray; }
    int getArraySize() { return arraySize; }
    


    // ====================== For Function ======================
    void setFuncDeclared() { this->funcDeclared = true; }
    void setFuncDefined(int definedLine = 0 ) {
        this->funcDefined = true; this->funcDeclared = true;
        if(definedLine != 0) this->definedLine = definedLine;
    }
    bool isFunction() { return funcDeclared; }
    bool isFuncDeclared() { return funcDeclared; }
    bool isFuncDefined() { return funcDefined; }
    void addParam(SymbolInfo *param) { params.push_back(param); }
    void addParams(const std::vector<SymbolInfo *> &params) { this->params.insert(this->params.end(), params.begin(), params.end()); }
    void setParams(const std::vector<SymbolInfo *> &params) { this->params = params; }
    std::vector<SymbolInfo *> getParams() { return params; }
    int getParamCount() { return params.size(); }
    void setDefinedLine(int definedLine) { this->definedLine = definedLine; }
    int getDefinedLine() { return definedLine; }



    // ====================== For Parse Tree ======================
    std::vector<SymbolInfo *> getChildren() { return children; }

    int getChildrenSize() { return children.size(); }

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



    // ====================== Overloaded Operators ======================
    friend std::ostream &operator<<(std::ostream &out, SymbolInfo &symbolInfo)
    {
        if (symbolInfo.isArray()) out << "<" << symbolInfo.name << ", ARRAY, " << symbolInfo.dataType << ">";
        else if(symbolInfo.isFunction()) {
            out << "<" << symbolInfo.name << ", FUNCTION, " << symbolInfo.dataType << ">";
            // print params
            // out << " (";
            // for (auto param : symbolInfo.params) {
            //     out << param->name << " ";
            // }
            // out << ")";
        }
        else out << "<" << symbolInfo.name << ", " << symbolInfo.dataType << ">";
        return out;
    }
};

#endif