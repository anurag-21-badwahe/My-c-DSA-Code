#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

int min(int a, int b)
{
    if (a < b)
    return a;
    return b;
}
void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int,list<int>> &adj, vector<int> &disc, vector<int> &low, int &parent, int &timer, vector<int> &ans)
{
    vis[node] = true;
    int child = 0;
    disc[node] = low[node] = timer++;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {     // edge case node = nbr && parent = node
            dfs(nbr, vis, adj, disc, low, node, timer, ans);
            low[node] = min(low[node],low[nbr]);

            // check articulation point
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ans[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }

        if(parent == -1 && child > 1){
            ans[node] = 1;
        }
    }
}

int main()
{
    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // creating adj list
    unordered_map<int,list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    int parent = -1;

    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ans(n, 0); //(size is n,starts from 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj,disc, low, parent, timer, ans);
        }
    }

    // printing articulation point
    cout << "articulation points are as follows" << endl;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}