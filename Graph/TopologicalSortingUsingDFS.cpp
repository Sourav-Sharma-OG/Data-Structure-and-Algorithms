#include<bits/stdc++.h>
using namespace std;

void topoSortUtil(int node, vector<int> &vis, vector<int>adj[], stack<int> &st){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(vis[it] == 0){
            topoSortUtil(it, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSorting(int v, vector<int>adj[]){
    vector<int>vis(v, 0);
    stack<int>st;
    for(int i = 0; i<v; i++){
        if(vis[i] == 0){
            topoSortUtil(i, vis, adj, st);
        }
    }
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main(){
    int v, e;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>topoSort = topologicalSorting(v, adj);
    for(auto it : topoSort){
        cout<<it<<" ";
    }
    return 0;
}