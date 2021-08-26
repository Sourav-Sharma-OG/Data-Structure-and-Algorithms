#include<bits/stdc++.h>
using namespace std;

int pageCount(int totalPages, int pageNo){
    int totalPagesTurnFromFront = totalPages / 2;
    int targetPagesTurnFromFront = pageNo / 2;
    int targetPagesTurnFromBack = totalPagesTurnFromFront - targetPagesTurnFromFront;

    return min(targetPagesTurnFromFront, targetPagesTurnFromBack);
}

int main(){
    int totalPages, pageNo;
    cin>>totalPages>>pageNo;

    cout<<pageCount(totalPages, pageNo);
    return 0;
}