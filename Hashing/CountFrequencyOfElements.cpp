#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, int> countFrequency(vector<int>arr){
    unordered_map<int, int>map;
    for(int i = 0; i<arr.size(); i++){
        map[arr[i]]++;
    }
    return map;
}

int main(){
    vector<int>arr = {1,5,3,4,8,1,3,4,1,6,2,4,8,9,3};
    unordered_map<int, int>map = countFrequency(arr);
    unordered_map<int,int> :: iterator it;
    cout<<"Key"<<" Value"<<endl;
    for(it = map.begin(); it != map.end(); it++){
        cout<<" "<<it->first<<"   "<<it->second<<endl;
    }
    return 0;
}