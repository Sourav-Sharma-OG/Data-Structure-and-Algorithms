/*
Efficient vineet (imp)(cogno ai /allincall researchs/capgemini)
Vineet Joshi organised an event called “Swach Bharat” in which at the end of each day, all the waste from the trash cans has been shifted into plastic bags which can carry waste weighing between 1.01 kg and 3.00 kg. All of the plastic bags must be dumped into the “Swatch Bharat Truck”. Vineet can carry at most 3.00 kg at once. One trip is described as selecting a few bag which together don’t weigh more than 3.00 kg, dumping them in 
the outdoor “Swatch Bharat Truck” and returning back to the place. Vineet wants to make minimum number of trips to the “Swatch Bharat Truck”. Given the number of plastic bags,  n, and the weights of each bag.
For example, given n = 5 plastic bags weighing weight = [1.01, 1.99, 2.5, 1.5, 1.01], Vineet can carry all of the trash in 3 trips: [1.01 + 1.99, 2.5, 1.5+1.01].
Constraints:
1 <= n <= 100000
1.01 <= weight[i] <= 3.0
Input:
First line contain an integer N which represent the number of plastic bags and next N lines contains weight of each plastic bags.
Output:
Output a single integer which tells the minimum number of trips taken by Vineet.
SAMPLE INPUT 
5
1.50
1.50
1.50
1.50
1.50
SAMPLE OUTPUT : 3
*/

#include<bits/stdc++.h>
using namespace std;

int countPaths(vector<double> arr, int W){
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1 ;

    int check = 0;
    while(left <= right){
        double temp = arr[left] + arr[right];
        if(temp <= W){
            check++;
            left++;
            right--;
        }
        else{
            check++;
            right--;
        }
    }
    return check;
}

int main(){
    vector<double> arr;
    int n ;
    cin>>n;

    for(int i = 0; i<n; i++){
        double ele;
        cin>>ele;
        arr.push_back(ele);
    }

    int ans = countPaths(arr, 3.0);
    cout<<ans;
}