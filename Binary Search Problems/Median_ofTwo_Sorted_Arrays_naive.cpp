#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        

        while(i < nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        
        while(j < nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
                
        int n = ans.size();
        double median;
        if(n % 2 == 0){
            median = (ans[(n-1)/2] + (double)ans[n/2]) / 2;
            return median;
        }
        
        median = ans[n/2];
        return median;        
    }

int main(){
    vector<int>nums1 = {1,2};
    vector<int>nums2 = {3,4};

    cout<<findMedianSortedArrays(nums1, nums2);
    return 0;
}