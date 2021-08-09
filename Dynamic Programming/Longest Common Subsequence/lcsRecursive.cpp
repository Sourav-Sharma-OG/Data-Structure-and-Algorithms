#include<bits/stdc++.h>
using namespace std;

int lcsLength(string s1, string s2, int x, int y){
    if(x == 0 || y == 0){
        return 0;
    }

    if(s1[x-1] == s2[y-1]){
        return 1 + lcsLength(s1, s2, x-1, y-1);
    }

    return max(lcsLength(s1, s2, x-1, y), lcsLength(s1, s2, x, y-1));
}

int main(){
    string s1 = "abcdaf";
    string s2 = "acbcf";
    cout<<lcsLength(s1, s2, s1.length(), s2.length());
    return 0;
}