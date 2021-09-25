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

vector<int> getShortestDist(vector<pair<int,int>>adj[], int v, int source){
    vector<int>dist(v+1, INT_MAX);
    queue<pair<int,int>>q;
    dist[source] = 0;
    q.push({source, 0});

    while(!q.empty()){
        int node = q.front().first;
        q.pop();

        for(auto it: adj[node]){
            if(dist[node] + it.second * node < dist[it.first]){
                dist[it.first] = dist[node] + it.second * node;
                q.push(it);
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
        adj[v].push_back({u, w});
    }

    int source;
    cin>>source;
    cout<<endl;
    vector<int>dist = getShortestDist(adj, v+1, 1);
    for(int it = 1; it<=v; it++){
        if(dist[it] == INT_MAX){
            cout<<"-1";
        }
        else{
            cout<<dist[it]<<endl;
        }
    } 
}