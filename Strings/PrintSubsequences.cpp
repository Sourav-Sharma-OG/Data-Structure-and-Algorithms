#include<bits/stdc++.h>
using namespace std;

void printSubsequences(string input, string output){
    if(input.empty()){
        cout<<output<<" ";
        return;
    }
    printSubsequences(input.substr(1), input[0] + output);
    printSubsequences(input.substr(1), output);
}

int main(){
    string s;
    cin>>s;
    printSubsequences(s, "");
    return 0;
}