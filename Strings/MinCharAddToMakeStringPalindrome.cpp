/*
Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
Examples: 
 

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int i = 0;
    int j = s.length() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

int minCharAddBruteForce(string s){
    int count = 0;

    while(s.length() > 0){
        if(isPalindrome(s)){
            break;
        }
        else{
            count++;
            //Erase the last element of the string
            s.erase(s.begin() + s.length() - 1);
        }
    }
    return count;
}

int main(){
    string s = "ABC";
    cout<<minCharAddBruteForce(s);
    return 0;
}