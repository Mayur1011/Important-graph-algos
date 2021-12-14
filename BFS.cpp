/*
Created by :- Mayur
Created on :- 2021-12-14 19:03:07
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
    }
    void printGraph()
    {
        for (int v = 1; v <= V; ++v)
        {
            cout << "\n Adjacency list of vertex " << v << ": head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            printf("\n");
        }
    }
    void BFS(int);
};

void Graph::BFS(int src)
{
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int csrc = q.front();
        q.pop();
        cout << csrc << " ";
        visited[csrc] = true;
        for (auto neigh : adj[csrc])
            if (!visited[neigh])
                q.push(neigh);
    }
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

        g.BFS(1);
    }
    return 0;
}