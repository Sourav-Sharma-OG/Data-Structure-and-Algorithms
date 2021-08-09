/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
*/

#include<bits/stdc++.h>
using namespace std;

int countWays(string s, int i, int j, bool isTrue){
    //If i becomes greater than j--> No possible string.
    if(i > j){
        return 0;
    }

    //If i == j --> Only one character in the string.
    //Return according to what is asked in the recursive call
    //i.e whether isTrue = true or isTrue = false;
    if(i == j){
        if(isTrue){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    int ans = 0;

    //k loops varies from k = i+1 to k = j-1 and k += 2
    //k is starting from i + 1 because at every i + 1 character there is operator and we have to divide our expression on 
    // an operator.
    //first recursive call -> countWays(s, i, k-1, true/false);
    //second recursive call -> countWays(s, k+1, j, true/false);
    for(int k = i+1; k<=j-1; k += 2){
        int lTrue = countWays(s, i, k-1, true);
        int lFalse = countWays(s, i, k-1, false);
        int rTrue = countWays(s, k+1, j, true);
        int rFalse = countWays(s, k+1, j, false);

        //If current operator is &
        if(s[k] == '&'){
            if(isTrue){
                ans += (lTrue * rTrue);
            }
            else{
                ans += (lTrue * rFalse) + (lFalse * rTrue) + (lFalse * rFalse);
            }
        }

        else if(s[k] == '|'){
            if(isTrue){
                ans += (lTrue * rTrue) + (lTrue * rFalse) + (lFalse * rTrue);
            }
            else{
                ans += (lFalse * rFalse);
            }
        }

        else if(s[k] == '^'){
            if(isTrue){
                ans += (lTrue * rFalse) + (lFalse * rTrue);
            }
            else{
                ans += (lTrue * rTrue) + (lFalse * rFalse);
            }
        }
    }

    return ans;
}


int main(){
    string s = "T|T&F^T";
    cout<<countWays(s, 0, s.length() - 1, true);
    return 0;
}