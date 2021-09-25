#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<pair<int, int>>adj[], vector<int>&vis, stack<int>&st){
    vis[node] = 1;
    
    for(auto it:adj[node]){
        if(vis[it.first] == 0){
            topologicalSort(it.first, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int>getShortestPath(int v, vector<pair<int, int>>adj[], int source){
    vector<int>vis(v, 0);
    stack<int>st;
    for(int i = 0; i<v; i++){
        if(vis[i] == 0){
            topologicalSort(i, adj, vis, st);
        }
    }

    vector<int>dist(v, INT_MAX);
    dist[source] = 0;
    st.push(source);
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it : adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    return dist;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<pair<int, int>>adj[v];
    for(int i = 0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    vector<int> shortestPaths = getShortestPath(v, adj, 0);
    for(auto i : shortestPaths){
        cout<<i<<" ";
    }
    return 0;
}