/*
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.
Example
Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes
*/

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int>adj[], vector<int> &vis, vector<int> &dfsvis){
    vis[node] = 1;
    dfsvis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycle(it, adj, vis, dfsvis)){
                return true;
            }
        }
        else if(vis[it] && dfsvis[it]){
            return true;
        }
    }

    dfsvis[node] = 0;
    return false;
}

bool isCycle(vector<int>adj[], int v){
    vector<int>vis(v, 0);
    vector<int>dfsvis(v, 0);

    for(int i = 0; i<v; i++){
        if(!vis[i]){
            if(checkCycle(i, adj, vis, dfsvis)){
                return true;
            }
        }
    }
    return false;
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

    if(isCycle(adj, v)){
        cout<<"Yes";
    }
    else{
        cout<<"False";
    }

    return 0;
}