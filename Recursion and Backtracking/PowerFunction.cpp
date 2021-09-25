#include<iostream>
using namespace std;

int pow(int x, int n){
    if(n == 0){
        return 1;
    }

    return x * pow(x, n-1);
}

int powLogTime(int x, int n){
    if(n == 0){
        return 1;
    }

    int powHalf = powLogTime(x, n/2);
    int ans = powHalf * powHalf;
    if(n %  2 == 1){
        ans = ans * x;
    }
    return ans;
}

int main(){
    int ans = pow(5, 4);
    int ans1 = powLogTime(2, 5);
    cout<<ans1<<endl;
    cout<<ans;
}