/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
*/

#include<bits/stdc++.h>
using namespace std;

int minReversals(string s){
    int n = s.length();
    if(n%2){
        return -1;
    }

    stack<char>st;
    for(int i = 0; i<n; i++){
        char ch = s[i];
        if(ch == '}' and !st.empty()){
            if(st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        else{
            st.push(ch);
        }
    }

    int openB = 0;
    int closeB = 0;

    while(!st.empty()){
        if(st.top() == '{'){
            openB++;
        }
        else{
            closeB++;
        }
        st.pop();
    }

    return (ceil(openB / 2.0) + ceil(closeB / 2.0));
}

int minReversalsBetter(string s){
    int n = s.length();
    if(n % 2){
        return -1;
    }

    int leftB = 0, rightB = 0;
    for(int i = 0; i<n; i++){
        char ch = s[i];
        if(ch == '{'){
            leftB++;
        }
        else{
            if(leftB == 0){
                rightB++;
            }
            else{
                leftB--;
            }
        }
    }

    return (ceil(leftB / 2.0) + ceil(rightB / 2.0));
}

int main(){
    string s = "}{{}}{{{";
    cout<<minReversals(s);
    cout<<endl;
    cout<<minReversalsBetter(s);
    return 0;
}