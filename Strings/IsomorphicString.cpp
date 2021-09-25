/*
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different
charactersin aab and xxy, i.e a and b
with frequency 2and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output: 0
Explanation: There are two different
charactersin aab but there are three
different charactersin xyz. So there
won't be one to one mapping between
str1 and str2.
*/

#include<iostream>
#include<string.h>
using namespace std;

bool areIsomorphic(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    int arr1[256] = {0};
    int arr2[256] = {0};

    for(int i = 0; i < s1.length(); i++){
        arr1[s1[i] - '0'] += 1;
        arr2[s2[i] - '0'] += 1;

        if(arr1[s1[i] - '0'] != arr2[s2[i] - '0']){
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "aab";
    string s2 = "xxy";

    if(areIsomorphic(s1, s2)){
        cout<<"Isomorphic";
    }
    else{
        cout<<"Not Isomorphic";
    }

    return 0;
}