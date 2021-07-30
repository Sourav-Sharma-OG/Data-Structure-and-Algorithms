/*
We need to reach at nth stair and we can take 1 step , 2 steps , 3 steps at a time.
Print all the possible ways to cover n stairs.
E.g :=> n = 3.
We can reach 3 -> {1, 1, 1}, {1, 2}, {2, 1}, {3};
*/


#include<bits/stdc++.h>
using namespace std;

vector<string>getStairsPath(int n){
    if(n == 0){
        vector<string>ans;
        ans.push_back(" ");
        return ans;
    }
    else if(n < 0){
        vector<string>ans;
        return ans;
    }

    vector<string>paths1 = getStairsPath(n-1);
    vector<string>paths2 = getStairsPath(n-2);
    vector<string>paths3 = getStairsPath(n-3);

    vector<string>ans;

    for(string s : paths1){
        string temp = "1" + s;
        ans.push_back(temp);
    }
     for(string s : paths2){
        string temp = "2" + s;
        ans.push_back(temp);
    }
     for(string s : paths3){
        string temp = "3" + s;
        ans.push_back(temp);
    }

    return ans;

}

int main(){
    vector<string>ans = getStairsPath(3);
    for(auto i : ans){
        cout<<i<<" ";
    }
}