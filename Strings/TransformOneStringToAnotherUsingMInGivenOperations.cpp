/*
Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

Examples: 

Input:  A = "ABD", B = "BAD"
Output: 1
Explanation: Pick B and insert it at front.

Input:  A = "EACBD", B = "EABCD"
Output: 3
Explanation: Pick B and insert at front, EACBD => BEACD
             Pick A and insert at front, BEACD => ABECD
             Pick E and insert at front, ABECD => EABCD
*/

#include<iostream>
#include<string.h>
#include<unordered_map>

using namespace std;

int minOperations(string s1, string s2){
    unordered_map<char, int>mp1;
    unordered_map<char, int>mp2;

    for(char ch : s1){
        mp1[ch]++;
    }

    for(char ch : s2){
        mp2[ch]++;
    }

    for(char ch : s2){
        if(mp1[ch] != mp2[ch]){
            return -1;
        }
    }

    int result = 0;
    for(int i = s1.length() - 1, j = s2.length() - 1; i >=0 and j >= 0;){
        while(i >=0 and s1[i] != s2[j]){
            result++;
            i--;
        }

        if(s1[i] == s2[j] and i >= 0){
            i--;
            j--;
        }
    }
    return result;
}

int main(){
    string s1 = "ABD";
    string s2 = "BAD";
    cout<<minOperations(s1, s2)<<endl;
    return 0;
}