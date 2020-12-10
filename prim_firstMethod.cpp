//  CS411 2020 Fall
//  hw7
//  Prim's algorithm
//  O(n^2)
//  Ling, Chenyi
//  Last updated on Dec/7/2020

#include <iostream>
#include <vector>

void prim(std::vector<std::vector<int>>& VGraph,
          std::vector<int>& lowcost,
          std::vector<int>& closest,
          std::vector<bool>& visited)
{
    std::size_t size = lowcost.size();
    visited[0] = true;
    
    for (int i = 1; i < size; i++)
    {
        lowcost[i] = VGraph[0][i];
        closest[i] = 0;
        visited[i] = false;
    }
    
    int weight = 0;

    std::cout << "Print the edges in MST：" <<std::endl;
  
    for (int i = 0; i < size-1; i++)
    {
        int min = 99999;
        int index = 1;
  
        for (int j = 0; j < size; j++)
        {
            if (lowcost[j] < min && !visited[j])
            {
                min = lowcost[j];
                index = j;
            }
        }
        weight += min;
   
        std::cout << "(" << closest[index] << "," << index << ")" << std::endl;

        visited[index] = true;
      
        for (int j = 1; j < size; j++)
        {
            if ((VGraph[index][j] < lowcost[j]) && (!visited[j]))
            {
                lowcost[j] = VGraph[index][j];
                closest[j] = index;
            }
        }
    }
    std::cout << "\nTotal weight of MST:" << weight << std::endl;
}

int main()
{
    // Create a graph
    int V, E;
    std::cout << "Enter number of vertices"<<std::endl;
    std::cin >> V;
    std::cout << "Enter number of edges"<<std::endl;
    std::cin >> E;
    std::vector<std::vector<int>> VGraph(V,std::vector<int>(V));
    std::vector<int> lowcost(V);
    std::vector<int> closest(V);
    std::vector<bool> visited(V);
  
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            VGraph[i][j] = 99999;
        }
    }
    
    // Set the edge weight
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
        VGraph[a][b] = VGraph[b][a] = length;
    }
    
    prim(VGraph, lowcost, closest, visited);
}
