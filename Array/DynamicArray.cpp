#include <iostream>
using namespace std;

void printMatrix(int **arr, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    int **arr = new int* [n];
    for(int i = 0; i<n; i++)
        arr[i] = new int[n];
        
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl<<endl;
    printMatrix(arr, n);

    return 0;
}