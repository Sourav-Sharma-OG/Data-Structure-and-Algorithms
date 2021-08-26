/*
There is a string s of lowercase English letters that is repeated infinitely many times. Given an integer n. Find and print the number of letter a's in the first n letters of the infinite string.
*/

#include<bits/stdc++.h>
using namespace std;

long long repeatedStrings(string s, int n){
    long a = 0;
    for(long i = 0; i<s.length(); i++){
        if(s[i] == 'a'){
            a++;
        }
    }
    
    long ans = (n / s.length()) * a;
    long check = n % s.length();
    for(long i = 0; i<check; i++){
        if(s[i] == 'a'){
            ans++;
        }
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    int n;
    cin>>n;

    cout<<repeatedStrings(str, n);
    return 0;
}