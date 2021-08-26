/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int merge(long long arr[], long long left, long long mid, long long right)
    {
        long long int inv = 0;
        long long n1 = mid - left + 1;
        long long n2 = right - mid;

        long long arr1[n1];
        long long arr2[n2];

        for (auto i = 0; i < n1; i++)
        {
            arr1[i] = arr[left + i];
        }

        for (auto i = 0; i < n2; i++)
        {
            arr2[i] = arr[mid + i + 1];
        }

        long long i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                arr[k] = arr1[i];
                i++;
                k++;
            }
            else
            {
                arr[k] = arr2[j];
                inv += n1 - i;
                k++;
                j++;
            }
        }

        while (i < n1)
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        while (j < n2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }

        return inv;
    }

    long long int merge_sort(long long arr[], long long left, long long right)
    {
        long long inv = 0;

        if (left < right)
        {
            long long int mid = (left + right) / 2;
            inv += merge_sort(arr, left, mid);
            inv += merge_sort(arr, mid + 1, right);
            inv += merge(arr, left, mid, right);
        }
        return inv;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort(arr, 0, N - 1);
    }
};

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        long long arr[N];

        for(auto i = 0; i<N; i++){
            cin>>arr[i];
        }

        Solution obj;
        cout<<obj.inversionCount(arr, N);
    }    

    return 0;
}