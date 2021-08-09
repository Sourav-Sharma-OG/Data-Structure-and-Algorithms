/*
Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
Example:
Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.
*/

#include <bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string s1)
{
    string s2 = s1;

    int m = s1.length();

    int dp[m + 1][m + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1] && i != j)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][m];
}

int main()
{
    string s = "AABEBCDD";
    cout << longestRepeatingSubsequence(s);

    return 0;
}