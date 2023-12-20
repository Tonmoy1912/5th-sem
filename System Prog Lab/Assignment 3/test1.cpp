#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v"); // Find the first non-whitespace character
    size_t last = str.find_last_not_of(" \t\n\r\f\v");   // Find the last non-whitespace character

    // Check for an empty string or all whitespace
    if (first == std::string::npos || last == std::string::npos)
        return "";

    // Extract the substring containing non-whitespace characters
    return str.substr(first, last - first + 1);
}

// Function to tokenize a string
std::vector<std::string> tokenize(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        // if(token==" "){
        //     continue;
        // }
        tokens.push_back(token);
        // cout<<token<<endl;
    }

    return tokens;
}

//to get words of a line
std::vector<std::string> extractWords(const std::string& input) {
    std::vector<std::string> words;
    std::istringstream iss(input);

    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

//to join string with punctuator
string join_str(vector<string> &arr,string p){
    string ans;
    for(auto it:arr){
        if(ans.size()!=0){
            ans+=p;
        }
        ans+=it;
    }
    return ans;
}

int main(){
    
    ifstream in("input1.asm");
    ofstream out("output_1.txt");
    string str;
    while(getline(in,str)){
        // cout<<str<<" ";
        out<<str<<endl;
    }

    // string str="   tonmoy biswas   ";
    // vector<string> arr=tokenize(str,' ');
    // for(auto it:arr){
    //     cout<<it;
    // }


    return 0;
}