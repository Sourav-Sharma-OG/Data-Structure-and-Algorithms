/*
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

The first element in s[k] starts with the selection of the element nums[k] of index = k.
The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
We stop adding right before a duplicate element occurs in s[k].
Return the longest length of a set s[k].

 

Example 1:

Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
Example 2:

Input: nums = [0,1,2]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

int maxlen(vector<int> &nums)
{
    //Time Complexity: O(N^2), Space Complexity: O(N)

    // unordered_set<int>unique;
    // int i = 0;
    // int ans = INT_MIN;
    // for(int i = 0; i<nums.size(); i++){
    //     int count = 0;
    //     while(true){
    //         if(unique.find(nums[i]) == unique.end()){
    //             unique.insert(nums[i]);
    //             count++;
    //             i = nums[i];
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     ans = max(count, ans);
    //     unique.clear();
    // }
    // return ans;

    //Time Complexity : O(N) Space Complexity : O(1)

    //         int res = INT_MIN;
    //         int count = 0;
    //         int temp;

    //         for(int i = 0; i<nums.size(); i++){
    //             if(nums[i] != -1){
    //                 temp = nums[i];
    //                 count = 0;
    //                 do{
    //                     nums[i] = -1;
    //                     temp = nums[temp];
    //                     count++;
    //                 }while(temp != nums[i]);
    //                 res = max(res, count);
    //             }
    //         }
    //         return res;

    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int size = 0;
        for (int j = i; nums[j] != -1; size++)
        {
            int temp = nums[j];
            nums[j] = -1;
            j = temp;
        }
        ans = max(size, ans);
    }
    return ans;
}


int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }

    cout << maxlen(nums);
    return 0;
}