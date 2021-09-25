/*
Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
Example: 
Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010” 
Output: 3 
Input: str = “0000000000” 
Output: -1
 */

#include<bits/stdc++.h>
using namespace std;

int splitt(string s){
    int ans = 0;
    int count0 = 0;
    int count1 = 0;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '0'){
            count0++;
        }
        else if(s[i] == '1'){
            count1++;
        }

        if(count0 == count1){
            ans++;
            count0 = 0;
            count1 = 0;
        }
    }
    return ans == 0 ? -1 : ans;
}

int main(){
    string s = "0100110101";
    cout<<splitt(s);
    return 0;
}