/*
Given a string S with repeated characters(only lowercase).The task is to rearrange character in a string that no two adjacent characters are same.
*/

#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

int canRearrange(string s){
    unordered_map<char, int>mp;
    for(char ch : s){
        mp[ch]++;
    }
    
    int maxi = 0;
    for(auto it : mp){
        maxi = max(maxi, it.second);
    }
    
    if(maxi <= s.length() - maxi + 1){
        return 1;
    }
    return 0;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
        if(canRearrange(s)){
            cout<<"Yes, can be rearranged."<<endl;
        }
        else{
            cout<<"No, cannot be rearranged."<<endl;
        }
	}
	return 0;
}