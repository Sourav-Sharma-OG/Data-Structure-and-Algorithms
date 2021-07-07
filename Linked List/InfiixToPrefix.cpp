#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c== '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPrefix(string str)
{
    reverse(str.begin(),str.end());
    stack<char> st;
    string res;
    for(int i = 0; i<str.size();i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            res += str[i];
        } 
        else if(str[i] == '(')
        {
            st.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prec(st.top()) >= str[i])
            {
                res += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string infix;
    cout<<"Enter an infix expression:- ";
    getline(cin,infix);
    cout<<"Prefix Evaluation: - ";
    cout<<InfixToPrefix(infix);


    return 0;
}