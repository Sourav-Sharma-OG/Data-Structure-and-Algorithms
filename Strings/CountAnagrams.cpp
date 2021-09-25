#include<bits/stdc++.h>
using  namespace std;

int countAnagrams(unordered_map<char, int>mp, vector<string>dict){
    int count = 0;
    for(auto i = 0; i < dict.size(); i++){
        bool inc = true;
        unordered_map<char, int>mp1;
        for(char ch : dict[i]){
            mp1[ch]++;
        }
        
        if(mp.size() == mp1.size()){
            for(char ch : dict[i]){
                if(mp[ch] != mp1[ch]){
                    inc = false;
                    break;
                }   
            }
        }
        else{
            inc = false;
        }
        if(inc){
            count++;
        }
    }
    return count;
}

vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    vector<int>ans;
    for(auto i = 0; i < query.size(); i++){
        unordered_map<char, int>mp;
        for(char ch : query[i]){
            mp[ch]++;
        }
        int temp = countAnagrams(mp, dictionary);
        ans.push_back(temp);
    }
    return ans;
}

int countAnagrams1(unordered_map<char, int>mp, vector<unordered_map<char, int>>mvp){
    int count = 0;
    for(auto i = 0; i < mvp.size(); i++){        
        if(mp == mvp[i]){
            count++;
        }
    }
    return count;
}

vector<int> stringAnagram1(vector<string> dictionary, vector<string> query) {
    vector<int>ans;
    vector<unordered_map<char,int>>mvp(dictionary.size());
        
    for(int i = 0; i < dictionary.size(); i++){
        string curr = dictionary[i];
        for(char ch : curr){
            mvp[i][ch]++;
        }
    }
    
    for(auto i = 0; i < query.size(); i++){
        unordered_map<char, int>mp;       
        for(char ch : query[i]){
            mp[ch]++;
        }
        int temp = countAnagrams1(mp, mvp);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int n, q;
    cin>>n>>q;
    vector<string>dict;
    vector<string>queue;

    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;
        dict.push_back(temp);
    }

    for(int i = 0; i < q; i++){
        string temp;
        cin>>temp;
        queue.push_back(temp);
    }

    vector<int>ans = stringAnagram(dict, queue);

    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}