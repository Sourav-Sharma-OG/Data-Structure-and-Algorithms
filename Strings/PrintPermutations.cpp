/*
Given a string S. The task is to print all permutations of a given string.
Example 1:
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include<bits/stdc++.h>
using namespace std;

void permutationsHelper(string input, string output, vector<string>& ans){
    if(input.empty()){
        ans.push_back(output);
    }

    for(int i = 0; i<input.length(); i++){
        char ch = input[i];
        string leftPart = input.substr(0, i);
        string rightPart = input.substr(i+1);
        string restOfString = leftPart + rightPart;
        permutationsHelper(restOfString, output + ch, ans);
    }
}

vector<string>getPermutations(string s){
    vector<string>ans;
    permutationsHelper(s, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string>ans = getPermutations(s);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}