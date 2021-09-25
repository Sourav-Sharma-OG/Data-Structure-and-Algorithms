/*
Write a program that extracts part of the given string from the specified position.For example, if the string is "Working 
with strings is fun", then if from position 4,4 characters are to be extracted then the program should return string as 
"king". Moreover, if the position from where thestring is to be extracted is given and the number of characters to be 
extracted is 0 then the program should extract entirestring from the specified position. (HP)
*.
*/


#include<iostream>
using namespace std;

string extract(string s, int start, int end){
	string ans = "";
	if(end == 0){
		for(int i = start - 1; i < s.length(); i++){
			ans += s[i];
		}
	}
	else{
		for(int i = start - 1; i < start + end - 1; i++){
			ans += s[i];
		}
	}
	return ans;
}

int main(){
	string s = "Working with strings is fun";
	cout<<"Extracted String is : --> : "<<extract(s, 4, 4);
	return 0;
}

