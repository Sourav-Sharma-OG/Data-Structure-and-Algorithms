/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
Use the input-output below to get more understanding on what is required
123 -> abc, aw, lc
993 -> iic
013 -> Invalid input. A string starting with 0 will not be passed.
103 -> jc
303 -> No output possible. But such a string maybe passed. In this case print nothing.
*/

#include<bits/stdc++.h>
using namespace std;

void printEncoding(string input, string output){
    if(input.empty()){
        cout<<output<<" ";
        return;
    }

    else if(input.length() == 1){
        char ch = input[0];
        if(ch == '0'){
            return;
        }
        else{
            int chVal = ch - '0';
            char alphabet = (char)('a' + chVal - 1);
            output += alphabet;
            cout<<output<<" ";
        }
    }

    else{
        char ch = input[0];
        string rosExcept1 = input.substr(1);

        if(ch == '0'){
            return;
        }
        else{
            int charVal = ch - '0';
            char alphabet = (char)('a' + charVal - 1);
            printEncoding(rosExcept1, output + alphabet);
        }

        string ch2 = input.substr(0, 2);
        string rosExcept12 = input.substr(2);

        int ch2Val = stoi(ch2);
        if(ch2Val <= 26){
            char alphabet = (char)('a' + ch2Val - 1);
            printEncoding(rosExcept12, output + alphabet);
        }
    }
}

int main(){
    string input;
    cin>>input;
    printEncoding(input, "");

    return 0;
}