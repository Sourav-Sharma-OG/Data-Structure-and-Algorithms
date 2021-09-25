/*
iven a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

int val(char ch){
    switch(ch){
        case 'I' : return 1;
        break;
        
        case 'V' : return 5;
        break;
        
        case 'X' : return 10;
        break;
        
        case 'L' : return 50;
        break;
        
        case 'C' : return 100;
        break;
        
        case 'D' : return 500;
        break;
        
        case 'M' : return 1000;
        break;
        
        default : return -1;
    }
}

int romanToDecimal(string &s) {
    // code here
    int ans = 0;
    for(int i = 0; i<s.length(); i++){
        if(i == s.length() - 1){
            ans += val(s[i]);
        }
        else if(val(s[i]) < val(s[i+1])){
            ans -= val(s[i]);
        }
        else{
            ans += val(s[i]);
        }
    }
    return ans;
}

int main(){
    string s = "XXIV";
    cout<<romanToDecimal(s);
    return 0;
}