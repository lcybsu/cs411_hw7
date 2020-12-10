//  CS411 2020 Fall
//  hw7
//  Prim's algorithm
//  O(E logV)
//  Ling, Chenyi
//  Last updated on Dec/10/2020

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>


const int mx = 10005;
 
typedef std::pair<int, int> P; //first is the edge weight when MST connects to that vertex, second is the vertex index
struct edge
{
    int weight;
    int to;
    edge(int weight = 0, int to = 0): weight(weight), to(to) {}
} e;
 
std::vector<edge> G[mx];
int disTo[mx]; // the edge weight of i when it connects to MST
bool vis[mx];
std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
 
int prim()
{
    P p;
    int v, i;
    int sumweight = 0;
    memset(disTo, 100, sizeof(disTo));
    memset(vis, 0, sizeof(vis));
    disTo[0] = 0;
    while (!pq.empty()) pq.pop();
    pq.push(P(0, 0));
    while (!pq.empty())
    {
        static_cast<void>(p = pq.top()), pq.pop();
        v = p.second; // v is e.from
        if (vis[v] || p.first > disTo[v]) continue;
        vis[v] = true;
        sumweight += disTo[v];
       
        for (i = 0; i < G[v].size(); ++i)
        {
            e = G[v][i];
            if (disTo[e.to] > e.weight)
            {
                disTo[e.to] = e.weight;
                pq.push(P(disTo[e.to], e.to));
            }
        }
        
    }
    return sumweight;
}
  
int main()
{
    int V, E;
    std::cout << "Enter number of vertices"<<std::endl;
    std::cin >> V;
    std::cout << "Enter number of edges"<<std::endl;
    std::cin >> E;
    
    for (int i = 0; i < V; ++i) G[i].clear();
    
    for (int i = 0; i < E; i++)
    {
        int a, b;
        std::cout << "Starting vertices: "<<std::endl;
        std::cin >> a;
        std::cout << "Ending vertices: "<<std::endl;
        std::cin >> b;
        std::cout << "Edge weight: "<<std::endl;
        int length;
        std::cin >> length;
        G[a].push_back(edge(length, b));
        G[b].push_back(edge(length, a));
    }
    
    std::cout <<"\nTotal weight of MST:"<< prim()<<std::endl;
    
    return 0;
}
