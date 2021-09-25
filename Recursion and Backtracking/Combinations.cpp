/*
1. You are give a number of boxes (nboxes) and number of identical items (ritems).
2. You are required to place the items in those boxes and print all such configurations possible.
Items are identical and all of them are named 'i'.
Note 1 - Number of boxes is greater than number of items, hence some of the boxes may remain empty.
*/

#include<bits/stdc++.h>
using namespace std;

void printCombinations(int currentBox, int totalBoxes, int selectedItems, int items, string itemsSelected){
    if(currentBox > totalBoxes){
        if(selectedItems == items){
            cout<<itemsSelected<<"   ";
        }
        return;
    }

    printCombinations(currentBox + 1, totalBoxes, selectedItems + 1, items, itemsSelected + "i");
    printCombinations(currentBox + 1, totalBoxes, selectedItems, items, itemsSelected + "_");
}

int main(){
    int nBoxes = 4;
    int rItems = 2;
    printCombinations(1, nBoxes, 0, rItems,"");
}