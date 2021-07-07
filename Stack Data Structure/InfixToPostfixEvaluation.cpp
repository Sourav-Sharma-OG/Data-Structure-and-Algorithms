/*
Algorithm to Convert Infix Expression into Postfix Expression.

-->If operand ==> print
-->If '(' ==> push to the stack.
-->If ')' ==> pop from the stack and print untill '(' is found.
-->if operator ==> pop from the stack and print untill operator with less precendence is not found.
*/

#include <iostream>
#include <stack>

using namespace std;

int precedence(char c)
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
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Postfix Evaluation: " << infixToPostfix(infix);

    return 0;
}