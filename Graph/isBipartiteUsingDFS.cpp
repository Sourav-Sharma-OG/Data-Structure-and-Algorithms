#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int node, vector<int>adj[], vector<int>&color){
    if(color[node] == -1)
        color[node] = 1;
    
    for(auto adjNode : adj[node]){
        if(color[adjNode] == -1){
            color[adjNode] = 1 - color[node];
            if(!checkBipartite(adjNode, adj, color))
                return false;
        }

        else if(color[adjNode] == color[node]){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<int>adj[], int v){
    vector<int>color(v+1, -1);
    for(int i = 0; i<v; i++){
        if(color[i] == -1){
            if(!checkBipartite(i, adj, color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<int>adj[v+1];
    for(int i = 0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartite(adj, v)){
        cout<<"Bipartite";
    }
    else{
        cout<<"Not Bipartite.";
    }

    return 0;
}