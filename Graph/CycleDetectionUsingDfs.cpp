#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int prev, vector<int>adj[], vector<bool> &vis){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(detectCycle(it, node, adj, vis)){
                return true;
            }
        }
        else if(vis[it] && it != prev){
            return true;
        }
    }
    return false;
}

bool isCycle(vector<int>adj[], int v){
    vector<bool>vis(v+1, false);
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            if(detectCycle(i, -1, adj, vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<int>adj[v+1];
    for(int i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isCycle(adj, v)){
        cout<<"Cycle Exists..";
    }
    else{
        cout<<"Cycle doesn't exists..";
    }
    return 0;
}