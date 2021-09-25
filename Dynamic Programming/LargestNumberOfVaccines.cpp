/*
A disease has spread in your country that does not have any vaccines. The health department of your country is working to create its vaccine. The limitation to create vaccines is the cost that is required to create an effective vaccine.
The scientists of the department have created 9 samples that are numbered from 1 to 9. Each vaccine is associated with a cost. The cost is denoted by an array X where Xi denotes the cost of ith sample. The health dept has been assigned N units of money to spend. This amount of money must be used to create stocks of vaccines that can be distributed among different hospitals that are situated at different locations in your country.
You are required to find the largest number of stocks possible that can be formed by using the N units of money, if it is not possible to form such a stock of vaccines, then print -1.
Constraints:

1 <= T <= 10^3
1 <= N <= 10^4
1 <= Xi <= 10^3

input:

4
5
9 4 2 2 6 3 2 2 1
2
5 11 2 2 5 8 9 10 19
5
9 9 9 9 9 9 9 9 9 9
32
7 8 9 8 7 9 8 8 10

output

99999
4
-1
9855

Explanation for 4th input and output
Cost of using digit 1 is 7
Cost of using digit 2 is 8
Cost of using digit 3 is 9 ....
Cost of using digit 9 is 10

Maximum number that we can make using 32 units of money is 9855 (Cost of digit 9 + Cost of digit 8 + Cost of digit 5 + Cost of digit 5) = (10 + 8 + 7 + 7) = 32
*/

#include<bits/stdc++.h>
using namespace std;

int largestNoOfStocks(int N, vector<int>cost){
    vector<int>dp(N+1, -1);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 9; j++){
            dp[i] = max(dp[i], cost[j] <= i ? 1 + dp[i - cost[j]] : -10000);
        }
    }

    if(dp[N] < 0){
        return -1;
    }

    string res = "";
    for(int i = 8; i >= 0; i--){
        while(N >= cost[i] and dp[N] == dp[N - cost[i]] + 1){
            res.push_back('1' + i);
            N -= cost[i];
        }
    }

    stringstream s(res);
    int ans = 0;
    s>>ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>cost;
        for(int i = 0; i < 9; i++){
            int ele;
            cin>>ele;
            cost.push_back(ele);
        }
        cout<<largestNoOfStocks(N, cost);
        cout<<endl;
    }
    return 0;
}