/*
Created by :- Mayur
Created on :- 2021-12-14 18:39:58
*/
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    // list<int> *adj;
    vector<int> *adj;

public:
    Graph()
    {
        V = 0;
    }
    Graph(int v)
    {
        this->V = v;
        // adj = new list<int>[V + 5];
        adj = new vector<int>[V + 5];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v); // comment this line for directed graphs
    }
    void printGraph()
    {
        for (int v = 1; v <= V; ++v)
        {
            cout << "\nAdjacency list of vertex " << v << ": head ";
            for (auto x : adj[v])
                cout << "-> " << x;
        }
    }
    // Add your function templates here...
    void DFSUtil(int, vector<bool> &);
    void DFS(int);
};
void Graph::DFSUtil(int src, vector<bool> &visited)
{
    cout << src << '\n';
    visited[src] = true;
    for (auto neigh : adj[src])
    {
        if (!visited[neigh])
        {
            DFSUtil(neigh, visited);
        }
    }
}
void Graph::DFS(int src)
{
    vector<bool> visited(V, false);
    DFSUtil(src, visited);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt = 1;
    //std::cin >> tt;
    while (tt--)
    {
        int V, E;
        cin >> V >> E;
        Graph g(V);

        for (int i = 0; i < E; i++)
        {
            int source, destination;
            cin >> source >> destination;
            g.addEdge(source, destination);
        }
        g.DFS(1);
    }
    return 0;
}