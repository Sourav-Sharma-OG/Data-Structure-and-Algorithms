/*
Given a string S consisting of N lowercase characters, the task is to find the length of the longest substring that does not contain any vowel.

Examples:

Input: S = “geeksforgeeks”
Output: 3
The substring “ksf” is the longest substring that does not contain any vowel. The length of this substring is 3.

Input: S = “ceebbaceeffo”
Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int longestSubstrings(string s){
    int maxSize = INT_MIN;
    int temp = 0;
    for(int i = 0; i < s.length(); i++){
        if(isVowel(s[i])){
            temp = 0;
        }
        else{
            temp ++;
        }
        
        maxSize = max(maxSize, temp);
    }
    return maxSize;
}


int main(){
    string s = "ceebbaceeffo";
    int ans = longestSubstrings(s);
    
    cout<<ans<<endl;
    return 0;
}