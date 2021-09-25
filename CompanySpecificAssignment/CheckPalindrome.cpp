/*
WAP to check Palindrome for string (cognizant)
*/

#include<iostream>
using namespace std;

bool isPalindrome(string s){
	int i = 0;
	int j = s.length() - 1;
	while(i < j){
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	if(isPalindrome(s)){
		cout<<"Yes, "<<s<<" is a palindrome.";
	}
	else{
		cout<<"No, "<<s<<" is not a palindrome";
	}
}
