/*
Write a program to sort a set of names stored in an array in alphabetical order. (HP)
*/

#include<iostream>
#include<string.h>
using namespace std;

void swap()

void sortNames(string arr[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(strcmp(arr[i], arr[j]) > 0){
				strcpy()
			}
		}
	}
}

int main(){
	string arr[] = {"Sourav", "Ravindar", "Priyanshu", "Raghav", "Shubham"};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	sortNames(arr, n);
	
	cout<<"Names in sorted order :"<<endl;
	
	for(auto it : arr){
		cout<<it<<" ";
	}
	return 0;
}

