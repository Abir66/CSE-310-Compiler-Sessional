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
        enterScope();
    }

    // create and enter a new scope
    void enterScope(){
        current_scope = new ScopeTable(bucketSize, ++scope_id, current_scope);
    }

    // delete the current scope
    void exitScope(){
        // root scope cannot be deleted
        if(current_scope == nullptr || current_scope->getParentScope() == nullptr){
            std::cout<<"\tScopeTable# " << current_scope->getId() << " cannot be removed"<<std::endl;
            return;
        }

        auto temp = current_scope;
        current_scope = current_scope->getParentScope();
        delete temp;
    }

    // insert a symbol in the current scope
    bool insert(std::string &name, std::string &type){
        if(current_scope == nullptr) enterScope();

        bool success = current_scope->insert(name, type);
        if(!success) std::cout<< "\t'"<<name<<"'"<<" already exists in the current ScopeTable"<<std::endl; 
        return success;
    }

    // look up a symbol in the current scope and all the parent scopes
    SymbolInfo* lookup(std::string &name){
        if(current_scope == nullptr) return nullptr;
        
        ScopeTable* curr = current_scope;
        SymbolInfo* symbol = nullptr;

        while(curr != nullptr){
            symbol = curr->lookup(name, true);
            if(symbol != nullptr)
                return symbol;
            curr = curr->getParentScope();
        }
        std::cout << "\t'" << name << "'" << " not found in any of the ScopeTables" << std::endl;
        return nullptr;
    }

    // delete a symbol from the current scope
    bool remove(std::string &name){
        if(current_scope == nullptr) return false;

        bool deleted = current_scope->deleteSymbol(name, true);
        if(!deleted) std::cout<<"\tNot found in the current ScopeTable"<<std::endl;
        return deleted;
    }

    // print the current scope
    void printCurrentScopeTable(){
        if(current_scope == nullptr) return;
        current_scope->print();
    }

    // print all the scopes
    void printAllScopeTable(){
        ScopeTable* curr = current_scope;
        while(curr != nullptr){
            curr->print();
            curr = curr->getParentScope();
        }
    }

    // destructor
    ~SymbolTable(){
        auto curr = current_scope;
        while(curr != nullptr){
            auto temp = curr;
            curr = curr->getParentScope();
            delete temp;
        }
    }


};

#endif