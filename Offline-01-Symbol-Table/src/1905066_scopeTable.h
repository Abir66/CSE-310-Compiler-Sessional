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
    unsigned int SDBMHash(std::string &str) {
	    unsigned int hash = 0;
	    unsigned int i = 0;
	    unsigned int len = str.length();

	    for (i = 0; i < len; i++)
	    {
		    hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
	    }

	    return hash;
    }

    int hash(std::string &str){
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
    }

    // getters
    int getBucketSize(){ return bucketSize; }
    int getId(){ return id; }
    ScopeTable* getParentScope(){ return parentScope; }

    // insert
    bool insert(std::string &key, std::string &type){

        if(lookup(key)!=nullptr){
            return false;
        }

        SymbolInfo* symbol = new SymbolInfo(key, type);
        int index = hash(key);
        int pos = 0;
        SymbolInfo *curr = symbolTable[index];

        if(curr == nullptr) symbolTable[index] = symbol;
        
        else{
            while (curr->getNext() != nullptr)
            {   
                curr = curr->getNext();
                pos++;
            }

            curr->setNext(symbol);
        }

        return true;
    }

    // lookup
    SymbolInfo* lookup(std::string &key){
        int index = hash(key);
        int pos = 0;

        SymbolInfo* curr = symbolTable[index];
        while(curr != nullptr){
            if(key == curr->getName()){
                std::cout<<"found"<<std::endl;
                return curr;
            }

            pos++;
            curr = curr->getNext();
        }

        std::cout<<"Not found"<<std::endl;
        return nullptr;
    }

    // delete symbol
    bool deleteSymbol(std::string key){

        int index = hash(key);
        int pos = 0;
        SymbolInfo* curr = symbolTable[index];
        SymbolInfo* prev = nullptr;

        while (curr != nullptr)
        {
            if(key == curr->getName()){
                // if the first element is being deleted
                if(prev == nullptr) symbolTable[index] = curr->getNext();
                else prev->setNext(curr->getNext());

                delete curr;
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

    }
};



#endif