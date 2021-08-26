/*
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

Examples : 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
*/

#include <bits/stdc++.h>
using namespace std;

void rightRotate(int arr[], int start, int end)
{
    int temp = arr[end];
    for (int i = end; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrangeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //Even index
        if (i % 2 == 0)
        {
            //Negative no.
            if (arr[i] < 0)
            {
                continue;
            }
            //Positive No.
            else
            {
                int j;
                for (j = i + 1; j < n; j++)
                {
                    if (arr[j] < 0)
                    {
                        rightRotate(arr, i, j);

                        break;
                    }
                }
            }
        }
        //Odd Index
        else
        {
            //Positive No.
            if (arr[i] >= 0)
            {
                continue;
            }
            //Negative No.
            else
            {
                int j;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] > 0)
                    {
                        rightRotate(arr, i, j);
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeArray(arr, n);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}