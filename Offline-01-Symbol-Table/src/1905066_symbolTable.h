#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include "1905066_scopeTable.h"


class SymbolTable{

    ScopeTable* current_scope;
    int bucketSize;
    int scope_id = 0;

public:

    // constructor
    SymbolTable(int bucketSize){
        this->current_scope = nullptr;
        this->bucketSize = bucketSize;
    }



    void enterScope(){
        current_scope = new ScopeTable(bucketSize, scope_id++, current_scope);
    }

    void exitScope(){
        if(current_scope == nullptr){
            return;
        }

        auto temp = current_scope;
        current_scope = current_scope->getParentScope();
        delete temp;
    }

    bool insert(){
        
    }




};

#endif