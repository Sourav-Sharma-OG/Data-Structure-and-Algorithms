/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.
Example 1:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".
*/

#include <bits/stdc++.h>
using namespace std;

bool helper(string s, int pos, unordered_set<string> &set, unordered_map<int, bool> &map){
    if(pos == s.length()){
        return map[pos] = true;
    }

    if(map.count(pos) == 1){
        return map[pos];
    }

    for(int i = pos; i<s.size(); i++){
        if(set.find(s.substr(pos, i - pos + 1)) != set.end()  and helper(s, i+1, set, map)){
            return map[pos] = true;
        }
    }
    return map[pos] = false;
}

bool wordBreak(string s, vector<string>& B){
    unordered_set<string>set;
    for(auto it : B){
        set.insert(it);
    }
    int pos = 0;
    unordered_map<int, bool>map;
    return helper(s, pos, set, map);
}

int main()
{
    vector<string> B = {"i", "like", "sam",
                        "sung", "samsung", "mobile",
                        "ice", "cream", "icecream",
                        "man", "go", "mango"};
    
    string A = "ilike";
    if(wordBreak(A, B)){
        cout<<"Possible";
    }else{
        cout<<"Not Possible";
    }

    return 0;
}