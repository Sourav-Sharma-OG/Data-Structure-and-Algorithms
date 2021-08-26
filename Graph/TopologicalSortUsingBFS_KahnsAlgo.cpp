#include<bits/stdc++.h>
using namespace std;

vector<int>topologicalSort(vector<int>adj[], int v){
    vector<int>topo;
    vector<int>indegree(v, 0);
    queue<int>q;

    //Calculating Indegrees
    for(int i = 0; i<v; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    //Pushing those vertices into the queue whose indegree is 0.
    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
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

    vector<int>topoSort = topologicalSort(adj, v);

    for(auto i : topoSort){
        cout<<i<<" ";
    }
    return 0;
}