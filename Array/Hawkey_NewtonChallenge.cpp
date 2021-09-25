/*

Hawkeye has been assigned to eliminate n monsters, the ith of which is of type ai. In one move, he can do either of the following:

i. Shoot down atmost any k monsters. In other words, he can shoot down any set of monsters such that the size of that set is smaller than or equal to k.
ii. Shoot down all monsters of any one type.

Find the minimum number of moves it will take him to shoot down all the monsters.
Input
The first line contains one integer t — the number of test cases. Each test case consists of two lines.
The first line contains two space-separated integers n and k.
The second line contains n space-separated integers a1, a2 . . . an.

Constraints:
1 ≤ t ≤ 105
1 ≤ k ≤ n ≤ 105
1 ≤ ai ≤ n
The sum of n over all test cases does not exceed 105.
Output
For each test case, print a single value - the minimum number of moves required.

Sample input
3
7 2
1 2 3 4 4 4 4
5 3
1 2 3 1 2
5 3
5 5 5 5 5

Sample output
3
2
1

Explanation:
For the first test case, the minimum moves required is 3. One way to do so is that Hawkeye can first shoot monsters 1 and 2 in one move using the second operation. 
Then he can shoot down all monsters of type 4 using the first operation, followed by shooting monster 3 by either method.
*/


#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int helper(int arr[], int n, int k){
    unordered_map<int, int>mp;
    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
    }

    int temp = k;
    vector<int>help;
    for(auto it : mp){
        help.push_back(it.second);
    }

    if(help.size() == 1){
        return 1;
    }
    sort(help.begin(), help.end());

    int ans = 1;
    for(int i = 0; i<help.size(); i++){
        if(temp >= help[i]){
            temp -= help[i];
        }else{
            ans++;
        }
    }
    return ans;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        cout<<helper(arr, n, k);
        cout<<endl;
    }
	return 0;
}