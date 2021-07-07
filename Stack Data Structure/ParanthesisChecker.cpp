/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form balaced pairs, with 0 number of unbalanced bracket.
Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, and here only 1 type of bracket is present and in balanced way.
Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
*/


#include<iostream>
#include<stack>

using namespace std;

bool checkParanthesis(string s){
    stack<char>st;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }

        else{
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }

            else  if(s[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }

            else  if(s[i] == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    }

    if(!st.empty()){
        return false;
    }
    return true;
}

int main(){
    string s = "{([])}";
    if(checkParanthesis(s)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced.";
    }
    return 0;
}