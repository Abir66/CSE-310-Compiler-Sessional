#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stack>


using namespace std;

std::ofstream codeIn;
std::ofstream tempOut;
std::ofstream optimzedCodeOut;

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

void printStack(stack<pair<string, string> >  &stack){
    while(!stack.empty()){
        cout << stack.top().first << endl;
        stack.pop();
    }
}

int main(){

    // generate optimized code from codeOut to optimzedCodeOut. use tempOut as a temporary buffer file
    ifstream codeIn("text.txt");

    stack<pair<string, string> > stack;
    vector<string> jumps = {"JMP", "JZ", "JNZ", "JG", "JGE", "JL", "JLE"};
    string jump_label = "";
    string jump_line = "";
    
    int i = 0;
    string line;
    while(getline(codeIn, line)){

        if(line[0] == ';'){
            cout<<line<<endl;
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

            if(jump_line != "") cout<<jump_line<<endl;
            cout<<line<<endl;
        }


        // if tokens[0] is a jump instruction
        else if(tokens[0] == "JMP" || tokens[0] == "JZ" || tokens[0] == "JNZ" || tokens[0] == "JG" || tokens[0] == "JGE" || tokens[0] == "JL" || tokens[0] == "JLE"){
            if(jump_line != "") cout<<jump_line<<endl;
            jump_line = line;
            jump_label = tokens[1];
        }

        else{
            if(jump_line != "") cout<<jump_line<<endl;
            cout<<line<<endl;
            jump_line = "";
            jump_label = "";
        }

                    
    }

    
    return 0;
}