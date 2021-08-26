#include<bits/stdc++.h>
using namespace std;

void printSubsequences(string input, string output){
    if(input.length() == 0){
        cout<<output<<" ";
        return;
    }

    char ch = input[0];

    printSubsequences(input.substr(1), output + "");
    printSubsequences(input.substr(1), output + ch);
}

int main(){
    string input = "abc";
    string output = "";
    printSubsequences(input, output);

    return 0;
}