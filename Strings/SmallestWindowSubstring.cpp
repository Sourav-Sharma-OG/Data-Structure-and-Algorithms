/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string p)
{
    if (p.length() > s.length())
    {
        return "-1";
    }
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    for (char ch : p)
    {
        mp2[ch]++;
    }

    int mct = 0;
    int dmct = p.length();
    string ans = "";
    int l = 0;

    for(int r = 0; r < s.length(); r++){
        mp1[s[r]]++;
        if(mp1[s[r]] <= mp2[s[r]]){
            mct++;
        }

        while(l < r and mct == dmct){
            string temp = s.substr(l, r - l + 1);
            if(ans.empty() || temp.length() < ans.length()){
                ans = temp;
            }
            if(mp1[s[l]] == 1){
                mp1.erase(s[l]);
            }
            else{
                mp1[s[l]]--;
            }

            if(mp1[s[l]] < mp2[s[l]]){
                mct--;
            }
            l++;
        }
    }
    return ans;
}

int main()
{
    string s = "timetopractice";
    string p = "toc";

    cout << minWindow(s, p);
}