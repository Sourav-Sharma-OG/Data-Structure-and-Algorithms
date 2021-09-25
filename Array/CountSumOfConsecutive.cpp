/*
Given a number N, the task is find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

 

Example 1:

Input:
N = 10
Output:
1
Explanation:
10 can be reprsented as sum of two or
more consecutive numbers in only one
way. 10 = 1+2+3+4.
Example 2:

Input:
N = 15
Output:
3
Explanation:
15 can be reprsented as sum of two or
more consecutive numbers in 3 ways.
(15 = 1+2+3+4+5); (15 = 4+5+6); (15 = 7+8).
*/

#include <bits/stdc++.h>
using namespace std;

int ways(int N)
{
    // int ans = 0;
    // for(int start = 1; start<N; start++){
    //     int end = start + 1;
    //     int sum = start + end;
    //     while(sum < N){
    //         end ++;
    //         sum += end;
    //     }
    //     if(sum == N){
    //         ans++;
    //     }
    // }
    // return ans;

    int ans = 0;
    int prefixSum[N + 1];
    prefixSum[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + i;
    }

    unordered_set<int> set;
    for (auto it : prefixSum)
    {
        set.insert(it);
    }

    for (int i = 0; i < N; i++)
    {
        if (set.find(prefixSum[i] - N) != set.end())
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n = 15;
    cout << ways(n);
    return 0;
}