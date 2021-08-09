#include<bits/stdc++.h>
using namespace std;

int main(){
    //n -> No of nodes.
    //m -> No of edges.
    int n, m;
    cin>>n>>m;

    //Declare adjacency matrix.
    int adj[n+1][n+1] = {};
    
    cout<<"Before Insertion:"<<endl;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;

    cout<<"Enter Edges from node u to node v: "<<endl;
    cout<<"u  v"<<endl;
    //Takes edges as input.
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        if(u > n || v > n){
            cout<<"wrong entry."<<endl;
        }
        //If matrix is Directed
        adj[u][v] = 1;

        //If matrix is Undirected 
        // adj[v][u] = 1;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}