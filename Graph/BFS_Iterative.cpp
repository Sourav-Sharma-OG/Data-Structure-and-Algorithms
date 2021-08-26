#include<bits/stdc++.h>
using namespace std;

vector<int> callBfs(int v, vector<bool>vis, vector<int> adj[], vector<int>&ans){
    queue<int> q;
    q.push(v);
    vis[v] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }

    return ans;
}

vector<int> bfs(int V, vector<int> adj[]){
    vector<int>ans;
    vector<bool>visited(V+1, false);
    
    for(int i = 1; i<=V; i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                ans.push_back(node);

                for(auto it: adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
            
        }
    }

    return ans;
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

    vector<int>ans = bfs(v,adj);
    for(auto i : ans){
        cout<<i<<" ";
    }
}