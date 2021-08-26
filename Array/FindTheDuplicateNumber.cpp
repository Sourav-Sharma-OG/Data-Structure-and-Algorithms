/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate1(vector<int> nums)
{
    int duplicate = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr = abs(nums[i]);
        if (nums[curr] < 0)
        {
            duplicate = curr;
            break;
        }
        nums[curr] *= -1;
    }

    return duplicate;
}

int findDuplicate2(vector<int> nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > 1)
        {
            return it->first;
        }
    }
    return -1;
}

int findDuplicate3(vector<int> nums)
{
    int tot = nums[0];
    int hare = nums[0];

    do{
        tot = nums[tot];
        hare = nums[nums[hare]];
    }while(tot != hare);

    tot = nums[0];
    while(tot != hare){
        tot = nums[tot];
        hare = nums[hare];
    }
    return hare;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate1(nums)<<endl;
    cout << findDuplicate2(nums)<<endl;
    cout << findDuplicate3(nums)<<endl;
}