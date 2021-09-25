//Write an efficient program to print all the duplicates and their counts in the input string 

#include<bits/stdc++.h>
using namespace std;

void printDuplicates(string s){
    unordered_map<char, int>mp;
    for(int i = 0; i<s.length(); i++){
        mp[s[i]]++;
    }

    for(auto it : mp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }

}

int main(){
    string s = "geeksforgeeks";
    printDuplicates(s);

    return 0;
}