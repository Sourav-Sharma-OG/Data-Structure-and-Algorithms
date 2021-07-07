#include<bits/stdc++.h>

using namespace std;

int precedence(char c){
    if(c == '^'){
        return 3;
    }

    else if(c == '*' || c == '/'){
        return 2;
    }

    else if(c == '+' || c == '-'){
        return 1;
    }

    else{
        return -1;
    }
}


string infixToPrefix(string s){
    stack<char>st;
    string ans = "";
    reverse(s.begin(), s.end());
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
    }

    for(int i = 0; i<s.length(); i++){

        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            ans += s[i];
        }

        else if(s[i] == '('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }

        else{
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    string a = "(a-b/c)*(a/k-l)";
    cout<<"Infix to prefix  conversion is: "<<infixToPrefix(a);

    return 0;
}