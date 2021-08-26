#include<bits/stdc++.h>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, int m, int n, int apples[], int oranges[]){
    int count = 0;
    for(int i = 0; i<m; i++){
        if(apples[i] >= 0){
            if(a + apples[i] >= s and a + apples[i] <= t){
                count++;
            }
        }
    }
    cout<<count<<endl;
    count = 0;

    for(int i = 0; i<n; i++){
        if(oranges[i] <= 0){
            if(b + oranges[i] <= t and b + oranges[i] >= s){
                count++;
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    int s, t;
    cin>>s>>t;

    int a, b;
    cin>>a>>b;

    int m, n;
    cin>>m>>n;

    int apples[m];
    int oranges[n];

    for(int i = 0; i<m; i++){
        cin>>apples[i];
    }

    for(int i = 0; i<n; i++){
        cin>>oranges[i];
    }

    cout<<endl<<endl;
    countApplesAndOranges(s, t, a, b, m, n, apples, oranges);
    return 0;
}