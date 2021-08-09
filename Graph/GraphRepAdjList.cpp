#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    //n-> No of nodes.
    //m-> No of edges.
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i<m; i++){
        cout<<"Adjancency List of Vertex "<<i<<" \n head ";
        for(auto i: adj[i]){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}