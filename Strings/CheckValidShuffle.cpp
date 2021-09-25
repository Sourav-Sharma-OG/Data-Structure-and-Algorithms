/*
Check if a string is the valid shuffle of two other strings.\
eg:- 
s1 = XY, s2 = 12, result = 1XY2.
1XY2 is a valid shuffle of XY and 12
*/

#include<bits/stdc++.h>
using namespace std;

bool validShuffle(string s1, string s2, string result){
    if(s1.length() + s2.length() != result.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(result.begin(), result.end());
    
    int i = 0;
    int j = 0;
    int k = 0;

    while(k != result.length()){
        if(i < s1.length() and s1[i] == result[k]){
            i++;
        }
        else if(j < s2.length() and s2[j] == result[k]){
            j++;
        }
        else{
            return false;
        }
        k++;
    }
    if(i < s1.length() or j < s2.length())
        return false;

    return true;
}

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    cout<<validShuffle(s1, s2, s3);
    return 0;
}