#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, vector<int>adj[], vector<bool>&vis){
    queue<pair<int, int>>q;
    q.push({node, -1});   
    vis[node] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();

        for(auto it : adj[curr]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, curr});
            }

            else if(vis[it] && prev != it){
                return true;
            }
        }
    }
    return false;

}

bool isCycle(vector<int>adj[], int v){
    vector<bool>vis(v+1, false);
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            if(detectCycle(i, adj, vis)){
                return true;
            }
        }   
    }
    return false;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<int> adj[v+1];
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
}