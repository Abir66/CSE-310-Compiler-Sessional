#ifndef OPTIMIZATION_HELPER_H
#define OPTIMIZATION_HELPER_H


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<stack>

using namespace std;


vector<string> split_string(const string& s) {
    vector<string> words;
    const string delimiters = " \t\n:,";
    string word;
    for (char c : s) {
        if (delimiters.find(c) != string::npos) { // if c is a delimiter
            if (!word.empty()) { // if word is not empty
                words.push_back(word); // add word to vector
                word.clear(); // clear the word string
            }
        } else {
            word += c; 
        }
    }
    if (!word.empty()) { // if there's a remaining word after the last delimiter
        words.push_back(word);
    }
    return words;
}

void printStack(stack<pair<string, string> >  &stack, std::ostream &out = std::cout){
    while(!stack.empty()){
        out << stack.top().first << endl;
        stack.pop();
    }
}

void remove_unnecessary_push_pop(string &source_file, string &target_file){
    
    ifstream codeIn(source_file);
    ofstream out(target_file);

    stack<pair<string, string> > stack;
    
    int i = 0;
    string line;
    while(getline(codeIn, line)){

        if(line[0] == ';'){
            out<<line<<endl;
            continue;
        }

        // tokenize the line
        vector<string> tokens = split_string(line);

        if(tokens[0] == "MOV" && tokens[1] == tokens[2]) continue;
        
        if(tokens[0] == "PUSH") {
            stack.push({line, tokens[1]});
            continue;
        }

        else if(tokens[0] == "POP"){
            if(stack.empty()) {
                out<<line<<endl;
                continue;
            }
            auto top = stack.top();
            stack.pop();

            if(tokens[1] != top.second){
                if(!stack.empty()) printStack(stack,out);
                out<<"okay"<<endl;
                out<<"\tMOV "<<tokens[1]<<", "<<top.second<<endl;
            }
        }

        else{
            if(!stack.empty()) printStack(stack,out);
            out<<line<<endl;
        }        
    }
}

void remove_unnecessary_jumps(string &source_file, string &target_file){
    
    ifstream codeIn(source_file);
    ofstream out(target_file);

    string jump_label = "";
    string jump_line = "";
    
    string line;
    while(getline(codeIn, line)){

        if(line[0] == ';'){
            out<<line<<endl;
            continue;
        }

        // tokenize the line
        vector<string> tokens = split_string(line);

        if(tokens[0] == "JMP" && tokens.size() == 1) continue;

        if(tokens[0][0] == 'L'){
            if(jump_label == tokens[0]){
                jump_line = "";
                jump_label = "";
            }

            if(jump_line != "") out<<jump_line<<endl;
            out<<line<<endl;
        }

        // if tokens[0] is a jump instruction
        else if(tokens[0] == "JMP" || tokens[0] == "JZ" || tokens[0] == "JNZ" || tokens[0] == "JG" || tokens[0] == "JGE" || tokens[0] == "JL" || tokens[0] == "JLE"){
            if(jump_line != "") out<<jump_line<<endl;
            jump_line = line;
            jump_label = tokens[1];
        }

        else{
            if(jump_line != "") out<<jump_line<<endl;
            out<<line<<endl;
            jump_line = "";
            jump_label = "";
        }             
    }
}

#endif