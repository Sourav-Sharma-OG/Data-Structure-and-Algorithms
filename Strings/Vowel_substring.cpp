#include<bits/stdc++.h>
using namespace std;


bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}

string findSubstring(string s, int k) {
    string tempAns = "";
    string result = "";
    int count = 0;
    
    for(int i = 0; i < k; i++){
        tempAns += s[i];
        if(isVowel(s[i])){
            count++;
        }
    }
    result = tempAns;
    
    for(int i = k; i < s.length(); i++){
        tempAns.erase(0, 1);
        tempAns += s[i];
        int oldCount = count;
        
        if(isVowel(s[i-k])){
            count--;
        }
        
        if(isVowel(s[i])){
            count++;
        }
        
        if(count > oldCount){
            result = tempAns;
        }
    }
    
    return result;
}

int main(){
    string s = "caberqiitefg";
    int k = 5;

    cout<<findSubstring(s, k);
    return 0;
}