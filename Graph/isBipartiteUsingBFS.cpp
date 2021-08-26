/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
*/
#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int source, vector<int> adj[], vector<int> &color){
    queue<int> q;
    q.push(source);
    color[source] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto adjNode : adj[node]){
            if(color[adjNode] == -1){
                color[adjNode] = 1 - color[node];
                q.push(adjNode);
            }
            else if(color[adjNode] == color[node]){
                return false;
            }
        }
    }
    return true;
    
}

bool isBipartite(vector<int> adj[], int v){
    vector<int> color(v+1, -1);
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
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isBipartite(adj, v)){
        cout<<"Given graph is Bipartite.";
    }
    else{
        cout<<"Given graph is not a Bipartite Graph.";
    }

    return 0;
}