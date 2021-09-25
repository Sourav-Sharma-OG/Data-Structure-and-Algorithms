#include<bits/stdc++.h>
using namespace std;

struct HeapNode{
    int val;
    int row;
    int col;
};

void swap(HeapNode* a, HeapNode* b){
    HeapNode c = *a;
    *a = *b;
    *b = c;
}

void minHeapify(HeapNode harr[], int idx, int heapSize){
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    int smallest = idx;

    if(left < heapSize and harr[left].val < harr[smallest].val){
        smallest = left;
    }

    if(right < heapSize and harr[right].val < harr[smallest].val){
        smallest = right;
    }

    if(smallest != idx){
        swap(&harr[idx], &harr[smallest]);
        minHeapify(harr, smallest, heapSize);
    }
}

void buildHeap(HeapNode harr[], int heapSize){
    for(int i = (heapSize-1) / 2; i>=0; i--){
        minHeapify(harr, i, heapSize);
    }
}

int kthElement(vector<vector<int>>& mat, int n, int k){
    HeapNode harr[n];
    for(int i = 0; i<n; i++){
        harr[i] = {mat[0][i], 0, i};
    }

    HeapNode ans;

    for(int i = 0; i<k; i++){
        ans = harr[0];

        int nextVal = (ans.row < (n - 1)) ? mat[ans.row + 1][ans.col] : INT_MAX;
        harr[0] = {nextVal, (ans.row) + 1, ans.col};

        minHeapify(harr, 0, n);
    }
    return ans.val;
}

int main(){
    vector<vector<int>>mat = {{16, 28, 60, 64},
                             {22, 41, 63, 91},
                             {27, 50, 87, 93},
                             {36, 78, 87, 94 }};

    int k = 3;
    
    cout<<kthElement(mat, mat.size(), k);
    return 0;
}