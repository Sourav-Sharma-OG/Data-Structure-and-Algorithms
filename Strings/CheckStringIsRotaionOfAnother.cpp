/*
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/

#include<bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    
    string temp = s1 + s1;

    if(temp.find(s2) != temp.npos)
        return true;
    return false;
}

bool areRotationsUsingQueue(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    
    queue<char>q1, q2;

    for(int i = 0; i<s1.length(); i++){
        q1.push(s1[i]);
        q2.push(s2[i]);
    }

    int k = s2.length();
    while(k--){
        char ch = q2.front();
        q2.pop();
        q2.push(ch);

        if(q2 == q1){
            return true;
        }
    }
    return false;
}

int main(){
    string s1 = "ABCD";
    string s2 = "CDAB";

    cout<<areRotationsUsingQueue(s1, s2);
    cout<<endl;
    cout<<areRotations(s1, s2);
    return 0;
}