/*
Given a graph with weight of each node as 1. Find the shortest distance from the source node to each other nodes.
Example:
v e
9 10
----
0 1
0 3
1 2
2 6
6 5
5 4
4 3
6 7
7 8
8 6
Enter source:0
OUTPUT: 0 1 2 1 2 3 3 4 4
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getShortestDist(vector<int>adj[], int v, int source){
    vector<int>path(v, INT_MAX);
    queue<int>q;
    path[source] = 0;
    q.push(source);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(path[node] + 1 < path[it]){
                path[it] = path[node] + 1;
                q.push(it);
            }
        }
    }
    return path;
}

int main(){
    int v, e;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cout<<"Enter source:";
    cin>>source;
    cout<<endl;
    vector<int>dist = getShortestDist(adj, v, source);
    for(auto it : dist){
        cout<<it<<" ";
    } 
}