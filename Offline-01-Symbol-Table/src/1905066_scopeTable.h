#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include<iostream>
#include<string>
#include "1905066_symbolInfo.h"

class ScopeTable
{
    SymbolInfo **symbolTable;
    int bucketSize;
    int id;
    ScopeTable *parentScope;


    // sdbm hash function
    // https://www.programmingalgorithms.com/algorithm/sdbm-hash/cpp/
    unsigned long long int SDBMHash(std::string &str) {
	    unsigned long long int hash = 0;
	    unsigned int i = 0;
	    unsigned int len = str.length();

	    for (i = 0; i < len; i++)
	    {
		    hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
	    }

	    return hash;
    }

    inline int hash(std::string &str){
        return SDBMHash(str) % bucketSize;
    }

public:

    // Constructors
    ScopeTable(){}
    ScopeTable(int bucketSize, int id, ScopeTable *parentScope = nullptr){
        this->bucketSize = bucketSize;
        this->id = id;
        this->parentScope = parentScope;
        symbolTable = new SymbolInfo*[bucketSize];
        for(int i = 0; i < bucketSize; i++) symbolTable[i] = nullptr;

        std::cout<<"\tScopeTable# " << id << " created"<<std::endl;
    }

    // getters
    int getBucketSize(){ return bucketSize; }
    int getId(){ return id; }
    ScopeTable* getParentScope(){ return parentScope; }

    // insert
    bool insert(std::string &name, std::string &type){

        if(lookup(name)!=nullptr){
            return false;
        }

        SymbolInfo* symbol = new SymbolInfo(name, type);
        int index = hash(name);
        int pos = 0;
        SymbolInfo *curr = symbolTable[index];

        if(curr == nullptr) symbolTable[index] = symbol;
        
        else{
            pos = 1;
            while (curr->getNext() != nullptr)
            {   
                curr = curr->getNext();
                pos++;
            }

            curr->setNext(symbol);
        }
        std::cout << "\tInserted in ScopeTable# " << id << " at position "<< index+1 <<", "<< pos+1 <<std::endl;
        return true;
    }

    // lookup
    SymbolInfo* lookup(std::string &name, bool printMessage = false){
        int index = hash(name);
        int pos = 0;

        SymbolInfo* curr = symbolTable[index];
        while(curr != nullptr){
            if(name == curr->getName()){
                if(printMessage) std::cout << "\t'" << name << "'" << " found in ScopeTable# " << id << " at position "<< index+1 <<", "<< pos+1 <<std::endl;
                return curr;
            }

            pos++;
            curr = curr->getNext();
        }

        return nullptr;
    }

    // delete symbol
    bool deleteSymbol(std::string &name, bool printMessage = false){

        int index = hash(name);
        int pos = 0;
        SymbolInfo* curr = symbolTable[index];
        SymbolInfo* prev = nullptr;

        while (curr != nullptr)
        {
            if(name == curr->getName()){
                // if the first element is being deleted
                if(prev == nullptr) symbolTable[index] = curr->getNext();
                else prev->setNext(curr->getNext());

                delete curr;
                if(printMessage)
                    std::cout << "\t" << "Deleted '" << name <<"'" << " from ScopeTable# " << id << " at position "<< index+1 <<", "<< pos+1 <<std::endl;

                return true;
            }

            pos++;
            prev = curr;
            curr = curr->getNext();
        }

        return false;
    }

    //print
    void print(){
        std::cout << "\tScopeTable# " << id << std::endl;
        for(int i = 0; i < bucketSize; i++){
            std::cout << "\t" << i+1 << "--> ";
            SymbolInfo* curr = symbolTable[i];
            while(curr != nullptr){
                std::cout << *curr << " ";
                curr = curr->getNext();
            }
            std::cout << std::endl;
        }
    }

    // destructor
    ~ScopeTable(){
        for(int i = 0; i < bucketSize; i++){
            SymbolInfo* curr = symbolTable[i];
            while(curr != nullptr){
                SymbolInfo* temp = curr;
                curr = curr->getNext();
                delete temp;
            }
        }
        delete[] symbolTable;
        std::cout << "\tScopeTable# " << id << " removed" << std::endl;
    }

};



#endif