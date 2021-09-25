/*
1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).
2. You are required to place the items in those boxes and print all such configurations possible.

Items are numbered from 1 to ritems.
Note 1 - Number of boxes is greater than number of items, hence some of the boxes may remain empty.
*/

#include<bits/stdc++.h>
using namespace std;

void printPermutations(vector<int>boxes, int ci, int ti){
    if(ci > ti){
        for(int i = 0; i < boxes.size(); i++){
            cout<<boxes[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i = 0; i < boxes.size(); i++){
        if(boxes[i] == 0){
            boxes[i] = ci;
            printPermutations(boxes, ci + 1, ti);
            boxes[i] = 0;
        }
    }
}
int main(){
    int nBoxes = 4;
    int rItems = 2;
    vector<int>boxes(nBoxes, 0);
    printPermutations(boxes, 1, rItems);
    return 0;
}