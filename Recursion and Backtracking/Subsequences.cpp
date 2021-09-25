#include<bits/stdc++.h>
using namespace std;

vector<string> getSubsequences(string str){
    vector<string> ans;
    if(str.length() == 0){
        ans.push_back(" ");
        return ans;
    }
    char ch = str[0];
    vector<string>temp = getSubsequences(str.substr(1));
    for(string s: temp){
        string b = ch + s;
        ans.push_back(s);
        ans.push_back(b);
    }
    return ans;
}

int main(){
    string s = "abc";
    vector<string>ans = getSubsequences(s);
    for(auto i : ans){
        cout<<i<<" ";
    }

    cout<<"\nNo. of  substrigs: "<<ans.size();
    return 0;
}