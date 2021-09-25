/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input : 
str1 = "heap", str2 = "pea" 
Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1
Explanation:
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.
*/

#include<bits/stdc++.h>
using namespace std;

void minNoOfDeletionsAndInsertions(string s1, string s2){
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];

    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<"Minimum no of deletions to make "<<s1<<" -> "<<s2<<" : "<<m - dp[m][n]<<endl;
    cout<<"Minimum no of insertions to make "<<s1<<" -> "<<s2<<" : "<<n - dp[m][n];
}

int main(){
    string s1 = "geek";
    string s2 = "gesek";
    minNoOfDeletionsAndInsertions(s1, s2);
    return 0;
}