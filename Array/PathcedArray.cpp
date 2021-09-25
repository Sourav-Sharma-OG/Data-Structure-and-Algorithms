/*
Given a sorted interger array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

 

Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

int minPatch(vector<int>& nums, int target){
    int i = 0;
    int count = 0;
    long long reach = 0;

    while(reach < target){
        if(i >= nums.size()){
            reach += reach + 1;
            count++;
        }

        else if(nums[i] <= (reach + 1)){
            reach += nums[i];
            i++;
        }

        else if(nums[i] > (reach + 1)){
            reach += reach + 1;
            count++;
        }
    }

    return count;
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int>nums;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }

    cout<<minPatch(nums, target);
    return 0;
}