/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>> intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for(auto interval : intervals){
        if(merged.empty() || merged.back()[1] < interval[0]){
            merged.push_back(interval);
        }
        else{
            merged.back()[1] = max(merged.back()[1], interval[1]); 
        }
    }

    return merged;
}

int main(){
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = mergeInterval(intervals);

    for(auto i : mergedIntervals){
        cout<<"["<<i[0]<<", "<<i[1]<<"], ";
    }

    return 0;
}