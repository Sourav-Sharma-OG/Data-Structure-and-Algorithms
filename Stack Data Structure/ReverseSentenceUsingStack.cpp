/*
Given string str consisting of multiple words, the task is to reverse the entire string word by word.
Examples:  

Input: str = “I Love To Code” 
Output: Code To Love I
Input: str = “data structures and algorithms” 
Output: algorithms and structures data 
 
 */

#include<iostream>
#include<stack>
using namespace std;

string reverseString(string str){
    stack<string>st;

    for(int i = 0; i<str.length(); i++){
        string temp = "";
        while(str[i] != ' ' && i<str.length()){
            temp += str[i];
            i++;
        }
        st.push(temp);
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top() + ' ';
        st.pop();
    }
    return ans;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    string ans = reverseString(str);
    cout<<"Reversed string is: "<<ans;

    return 0;
}