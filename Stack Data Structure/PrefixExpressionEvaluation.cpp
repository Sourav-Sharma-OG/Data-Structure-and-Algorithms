#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int prefixEvaluation(string prefix){
    stack<int>st;
    for(int i = prefix.length()-1; i>=0; i--){
        
        if(prefix[i] >= '0' && prefix[i] <= '9'){
            st.push(prefix[i] - '0');
        }
        else{
            int op1 = st.top();
            st.pop();

            int op2 = st.top();
            st.pop();

            switch (prefix[i])
            {
            case '+' : st.push(op1  + op2);
                break;

            case '-' : st.push(op1 - op2);
                break;

            case '*' : st.push(op1 * op2);
                break;
            
            case '/' : st.push(op1 /op2);
                break;

            case '^' : st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

int main(){
    string prefix = "+-+5*862*34";

    cout<<prefixEvaluation(prefix);
    return 0;
}