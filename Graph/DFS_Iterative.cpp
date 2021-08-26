#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
    //V -> No. of vertices.
    int V;

    //Adjacenct List.
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS();
    void DFS_Util(int source, vector<bool> &vis);
};

Graph ::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph ::DFS_Util(int source, vector<bool> &visited)
{
    stack<int> st;

    st.push(source);

    while (!st.empty())
    {
        source = st.top();
        st.pop();

        if (!visited[source])
        {
            cout << source << " ";
            visited[source] = true;
        }

        for (auto i = adj[source].begin(); i != adj[source].end(); i++)
        {
            if (!visited[*i])
            {
                st.push(*i);
            }
        }
    }
}

void Graph :: DFS()
{
    vector<bool> visited(V, false);
    for (int i = 1; i < V; i++)
    {
        if (!visited[i])
        {
            DFS_Util(i, visited);
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 5);
    g.addEdge(5, 7);
    g.addEdge(4, 6);

    cout << "Following is Depth First Traversal: " << endl;
    g.DFS();
    return 0;
}