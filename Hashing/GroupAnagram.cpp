#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> printAnagrams(vector<string>string_list){
    unordered_map<string, vector<string>>mp;
    for(auto s : string_list){
        string temp = s;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(s);
    }
    
    vector<vector<string>>ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<string>list = {"act","god","cat","dog","tac"};
    vector<vector<string>>ans = printAnagrams(list);
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}