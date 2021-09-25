/*
You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
*/

#include<bits/stdc++.h>
using namespace std;

int minSwaps(string s){
    int openingB = 0;
    int closingB  = 0;
    int swaps = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '['){
            if(closingB >= openingB){
                swaps += (closingB - openingB);
            }
            openingB++;
        }
        else{
            closingB++;
        }
    }
    return swaps;
}

int main(){
    string s = "[]][][";
    cout<<minSwaps(s);
    return 0;
}