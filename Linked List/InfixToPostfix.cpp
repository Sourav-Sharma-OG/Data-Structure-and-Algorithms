#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)     //This for loop will traverse the whole infix string. 
    {
        //Condition to check that given index of infix string is an operand.
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }

        //Condition to check that given index of infix string is '(' .
        else if (s[i] == '(')
        {
            //If true then push that into the stack.
            st.push(s[i]);
        }

        //Condtion to check that given index of infix string is ')'.
        else if (s[i] == ')')
        {
            //If true, then add the index element into the result postfix string untill the stack become empty and '(' is encounterd as top element. 
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }

            //If the '(' encountered and rest stack is empty then pop that '('.
            if (!st.empty())
            {
                st.pop();
            }
        }

        //Condition if the index element of infix string is an operator.
        else
        {
            //It will push the operand into the resulted postfix string untill the string become empty string and the precedence of top element is greater than the index 
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(! st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}


int main()
{
    string infix;
    cout<<"Enter an infix expression:- ";
    getline(cin,infix);

    cout<<"Postfix Equivalent is:- "<<infixToPostfix(infix);

    return 0;
}
