#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include<vector>
#include<limits.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int weight)
    {

        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src,vector<int>&dis,stack<int>&topo){
         dis[src] = 0;
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dis[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dis[top] + i.second < dis[i.first]){
                      dis[i.first] = i.second + dis[top];
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdges(0, 1, 5);
    g.addEdges(0, 2, 3);
    g.addEdges(1, 2, 2);
    g.addEdges(1, 3, 6);
    g.addEdges(2, 3, 7);
    g.addEdges(2, 4, 4);
    g.addEdges(2, 5, 2);
    g.addEdges(3, 4, -1);
    g.addEdges(4, 5, -2);

    g.printAdj();

    // TOPOLOGICAL SORT
    unordered_map<int, bool> visited;
    stack<int> s;
    int noOfNode = 6;
    int n = noOfNode;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
        g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int>dis(n);
    
    for(int i = 0; i < n; i++){
        dis[i] = INT_MAX;
    }
  g.getShortestPath(src,dis,s);

  cout << "answer is"<<endl;
  for(int i = 0; i < dis.size(); i++){
    cout << dis[i] << endl;
  }
  cout << endl;

}