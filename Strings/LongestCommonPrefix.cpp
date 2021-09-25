/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include<bits/stdc++.h>
using namespace std;

string Lcp(vector<string>&s){
    if(s.size() == 0){
        return "";
    }

    string lcp = s[0];
    for(int i = 1; i<s.size(); i++){
        string currentWord = s[i];
        int j = 0;

        while(j < currentWord.length() and j < lcp.length() and lcp[j] == currentWord[j]){
            j++;
        }

        if(j == 0){
            return "";
        }

        lcp = currentWord.substr(0, j);
    }
    return lcp;
}

int main(){
    vector<string>s = {"flower","flow","flight"};
    cout<<Lcp(s);
    return 0;
}