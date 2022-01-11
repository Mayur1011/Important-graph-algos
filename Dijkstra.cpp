/*
Created by :- Mayur
Created on :- 2021-12-14 19:41:29
*/
#include <bits/stdc++.h>

using namespace std;

class Graph
{
  int V;
  // list<int> *adj;
  vector<vector<pair<int, int>>> adj;

public:
  Graph()
  {
    V = 0;
  }
  Graph(int v)
  {
    this->V = v;
    // adj = new list<int>[V + 5];
    adj.resize(V + 5);
  }
  void addEdge(int u, int v, int w)
  {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  void printGraph()
  {
    for (int v = 1; v <= V; ++v)
    {
      cout << v << " --> ";
      for (auto x : adj[v])
        cout << "{" << x.first << "," << x.second << "} ";
      printf("\n");
    }
  }
  void Dijkstra(int);
};
void Graph::Dijkstra(int src)
{
  /* 
     [Single Source Shortest Path]
     This algorithm is all about finding the shortest distance for all the nodes form a particular node (single source node). 
  */
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  // {distance, source} -- arrange based on minimum distance
  q.push({0, src});
  vector<int> mindistance(V + 1, 1e9);
  mindistance[src] = 0;
  while (!q.empty())
  {
    int csrc = q.top().second;
    q.pop();

    for (auto [cdest, cwt] : adj[csrc])
    {
      // int cdest = neigh.first;
      // int cwt = neigh.second;
      if (mindistance[cdest] > mindistance[csrc] + cwt)
      {
        mindistance[cdest] = mindistance[csrc] + cwt;
        q.push({mindistance[cdest], cdest});
      }
    }
    for (int i = 0; i < mindistance.size(); i++)
      cout << i << " --> " << mindistance[i] << '\n';
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
      int source, destination, weight;
      cin >> source >> destination >> weight;
      g.addEdge(source, destination, weight);
    }
    g.Dijkstra(1);
  }
  return 0;
}