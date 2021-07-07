#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int postfixEvaluation(string postfix){
    stack<int>st;
    for(int i = 0; i<postfix.length(); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            st.push(postfix[i] - '0');
        }

        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch(postfix[i]){
                case '+' : st.push(op1 + op2);
                break;

                case '-' : st.push(op1 - op2);
                break;

                case '*' : st.push(op1 * op2);
                break;

                case '/' : st.push(op1 / op2);
                break;

                case '^' : st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

int main(){
    string postfix = "46+2/5*7+";
    cout<<"Postfix evaluation: "<<postfixEvaluation(postfix);
    return 0;
}