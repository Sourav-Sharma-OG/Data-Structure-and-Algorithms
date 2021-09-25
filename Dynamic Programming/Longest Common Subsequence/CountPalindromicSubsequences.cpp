/*
Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;
Example 1:
Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
Example 2:
Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*<----------------------------------------------------------------------------------------------------------->*/
//Brute Force with time complexity : O(2^n . n)
bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    if (s.length() == 0)
    {
        return false;
    }
    return true;
}

void helper(string input, string output, long long int &ans)
{
    if (input.empty())
    {
        if (isPalindrome(output))
        {
            ans++;
        }
        return;
    }

    helper(input.substr(1), output + input[0], ans);
    helper(input.substr(1), output, ans);
}

int countPalindromicSub(string s)
{
    long long int ans = 0;
    helper(s, "", ans);
    return ans % mod;
}
/*<----------------------------------------------------------------------------------------------------------->*/

int countPalindromeBottomUp(string s)
{
    int n = s.length();
    int dp[n][n];

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                dp[i][j] = s[i] == s[j] ? 3 : 2;
            }
            else
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % mod;
                }
                else
                {
                    // dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % mod;
                    /**
                     * For operations where subtraction is required, 
                     * it is better to write-> (a-b+mod)%mod 
                     * than-> (a-b)%mod To avoid modulus of negative values
                     */
                    long long a = (dp[i][j - 1] + dp[i + 1][j]) % mod;
                    long long b = dp[i + 1][j - 1];
                    dp[i][j] = ((a - b + mod) % mod) % mod;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s = "abcd";
    cout << countPalindromicSub(s);
    cout << endl;
    cout << countPalindromeBottomUp(s);
    return 0;
}