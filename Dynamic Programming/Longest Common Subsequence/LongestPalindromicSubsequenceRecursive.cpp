/*
Given a sequence, find the length of the longest palindromic subsequence in it.
-->As another example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest       palindromic subsequence in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given   sequence, but not the longest ones.*/

#include<bits/stdc++.h>
using namespace std;

int lps(string s, int start, int end){
    //Case when pointers overlap each other.
    if(start == end){
        return 1;
    }

    //Case when there are only two characters left in the string.
    if(s[start] == s[end] && start + 1 == end){
        return 2;
    }

    //If the current fist and last characters are equal 
    if(s[start] == s[end]){
        return 2 + lps(s, start + 1, end - 1);
    }

    //If not equal.
    return max(lps(s, start + 1, end), lps(s, start, end-1));
} 

int main(){
    string s = "GEEKSFORGEEKS";
    cout<<lps(s, 0, s.length()-1);
}