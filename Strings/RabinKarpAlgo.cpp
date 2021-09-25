#include<bits/stdc++.h>
using namespace std;

void searchPatternNaiveApproach(char txt[], char pat[], int m, int n){
    for(int i = 0; i<=m-n; i++){
        int j;
        for(j = 0; j<n;j++){
            if(txt[i+j] != pat[j]){
                break;
            }
        }

        if(j == n){
            cout<<"Pattern found at index "<<i<<endl;
        }
    }
}

void searchPatternRabinKarp(char txt[], char pat[], int n, int m){
    int d = 256;
    int i , j;

    //A prime number
    int q = 101;
    //Hash value for pattern
    int p = 0;

    //Hash value for text
    int t = 0;

    int h = 1;
    //The value of h would be pow(d, m-1) % q
    for(int i = 0; i<m-1; i++){
        h = (h * d) % q;
    }

    //Calculate the hash value of pattern and first window of text
    for(int i = 0; i<m; i++){
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    //Slide the pattern over text one by one.
    for(int i = 0; i<=n-m; i++){
        if(p == t){
            for(j = 0; j<m; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j == m){
                cout<<"Pattern found at index "<<i<<endl;
            }
        }

        if(i < n-m){
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if(t < 0){
                t = (t + q);
            }
        }
    }

}

int main(){
    int m, n;
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";

    m = strlen(txt);
    n = strlen(pat);

    searchPatternNaiveApproach(txt, pat, m, n);

    cout<<endl<<endl;

    searchPatternRabinKarp(txt, pat, m, n);
    return 0;
}