/*
Created by :- Mayur
Created on :- 
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
        adj[w].push_back(v); // comment this line for directed graph
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
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt = 1;
    //std::cin >> tt;
    while (tt--)
    {
    }
    return 0;
}