/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.
Examples :  

Input : str = “geek” 
Output : 2 
We need to make minimum 2 cuts, i.e., “g ee k”
Input : str = “aaaa” 
Output : 0 
The string is already a palindrome.
Input : str = “abcde” 
Output : 4
Input : str = “abbac” 
Output : 1 
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromicPartitions(string  s, int i, int j){
    if(i >= j || isPalindrome(s, i, j)){
        return 0;
    }

    int ans = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempAns = palindromicPartitions(s, i, k) + palindromicPartitions(s, k+1, j) + 1;

        ans = min(ans, tempAns);
    }

    return ans;
}

int main(){
    string s = "abbac";
    cout<<palindromicPartitions(s, 0, s.length()-1);
    return 0;
}