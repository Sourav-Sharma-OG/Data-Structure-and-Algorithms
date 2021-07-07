#include<iostream>
#include<stack>

using namespace std;

bool checkBalancedParanthesis(string str){
    if(str.empty()){
        cout<<"String is empty.";
        return false;
    }

    stack<char>s1;

    for(int i =0; i<str.size(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s1.push(str[i]);
        }

        else if(str[i] == ')'){
            if(s1.top() == '('){
                s1.pop();
            }
            else{
                return false;
            }
        }

        else if(str[i] == '}'){
            if(s1.top() == '{'){
                s1.pop();
            }
            else{
                return false;
            }
        }
        else if(str[i] == ']'){
            if(s1.top() == '['){
                s1.pop();
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main(){

    string a = "{[()]}";
    bool ans = checkBalancedParanthesis(a);
    if(ans == true){
        cout<<"Parenthesis are Balanced.";
    }
    else{
        cout<<"Parenthesis are not Balanced.";
    }


    return 0;
}