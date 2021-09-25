/*
Implementation of string copy, reverse, length, concatenation, comparison, lowercase
and upper case conversion without inbuilt functions.(HP)
*/

#include<iostream>
#include<string.h>
using namespace std;

int lengthOf(string s){
	int i = 0;
	while(s[i]){
		i++;
	}
	return i;
}

string copyString(string s){
	return s;
}

string toLowercase(string s){
	int len = lengthOf(s);
	for(int i = 0; i < len; i++){
		if(s[i] >= 'A' and s[i] <= 'Z'){
			s[i] = s[i] + 32;
		}
	}
	return s;
}

string toUppercase(string s){
	int len = lengthOf(s);
	for(int i = 0; i < len; i++){
		if(s[i] >= 'a' and s[i] <= 'z'){
			s[i] = s[i] - 32;
		}
	}
	return s;
}

string concatencate(string a, string b){
	int i = 0;
	int len = lengthOf(b);
	
	while(len--){
		a += b[i];
		i++;
	}
	return a;
}

int compareStrings(string a, string b){
	int i = 0;
	int j = 0;
	
	while(a[i]){
		if(a[i] != b[i]){
			break;
		}
		i++;
		j++;
	}	
	return (int)a[i] - (int)b[j];
}

int main(){
	string s;
	cout<<"Enter a String: ";
	cin>>s;
	
	cout<<"Length of string: "<<lengthOf(s)<<endl;
	
	string copy = copyString(s);
	cout<<"Copied string is: "<<copy<<endl;
	
	cout<<"String in lowercase is: "<<toLowercase(s)<<endl;
	cout<<"String in uppercase is: "<<toUppercase(s)<<endl;
	cout<<"Concatenation of original and copied string is: "<<concatencate(s, copy)<<endl;
	cout<<"Comparing string s with copied string: "<<compareStrings("Sourav", "Sharma")<<endl;
}
