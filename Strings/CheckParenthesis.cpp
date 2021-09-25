/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkParenthesis(string x)
{
    stack<char> st;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            st.push(x[i]);
        }
        else
        {
            if (x[i] == ')')
            {
                if (!st.empty() and st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (x[i] == ']')
            {
                if (!st.empty() and st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (x[i] == '}')
            {
                if (!st.empty() and st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return st.empty();
}

int main()
{
    string s = "{([])}";
    if(checkParenthesis(s)){
        cout<<"BALANCED";
    }
    else{
        cout<<"NOT BALANCED";
    }

    return 0;
}