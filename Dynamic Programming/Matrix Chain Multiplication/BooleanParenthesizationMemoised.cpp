#include <bits/stdc++.h>
using namespace std;

int dp[201][201][2];

int countWays(string &s, int i, int j, bool isTrue)
{
    if (dp[i][j][isTrue] != -1)
    {
        //Doing mod 1003 because given in problem statement.
        return dp[i][j][isTrue] % 1003;
    }

    if (i > j)
    {
        return dp[i][j][isTrue] = 0;
    }

    if (i == j)
    {
        if (isTrue)
        {
            return dp[i][j][isTrue] = s[i] == 'T'? 1 : 0;
        }
        else
        {

            return dp[i][j][isTrue] = s[i] == 'F'? 1 : 0;
        }
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lTrue = countWays(s, i, k - 1, true);
        int lFalse = countWays(s, i, k - 1, false);
        int rTrue = countWays(s, k + 1, j, true);
        int rFalse = countWays(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
            {
                ans += (lTrue * rTrue);
            }
            else
            {
                ans += (lTrue * rFalse) + (lFalse * rTrue) + (lFalse * rFalse);
            }
        }

        else if (s[k] == '|')
        {
            if (isTrue)
            {
                ans += (lTrue * rTrue) + (lTrue * rFalse) + (lFalse * rTrue);
            }
            else
            {
                ans += (lFalse * rFalse);
            }
        }

        else if (s[k] == '^')
        {
            if (isTrue)
            {
                ans += (lTrue * rFalse) + (lFalse * rTrue);
            }
            else
            {
                ans += (lTrue * rTrue) + (lFalse * rFalse);
            }
        }
    }

    return dp[i][j][isTrue] = ans % 1003;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s = "T|T&F^T";
    cout << countWays(s, 0, s.length() - 1, true);
    return 0;
}