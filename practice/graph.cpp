#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int> *l; // int *arr

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        if (u < 0 || v < 0 || u >= V || v >= V)
        {
            cout << "Invalid edge: (" << u << ", " << v << ")\n";
            return;
        }
        l[u].push_back(v);
        // l[v].push_back(u); // For undirected Graph comment it to use directed Graph
    }

    // void printAdjList()
    // {
    //     for (int i = 0; i < V; i++)
    //     {
    //         cout << i << " : ";
    //         for (int neigh : l[i])
    //         {
    //             cout << neigh << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // void findDegrees()
    // {
    //     for (int i = 0; i < V; i++)
    //     {
    //         cout << "Degree of vertex " << i << "=" << l[i].size() << endl;
    //     }
    // }

    // void bfs()
    // {
    //     queue<int> Q;
    //     vector<bool> vis(V, false);
    //     Q.push(0);
    //     vis[0] = true;

    //     while (Q.size() > 0)
    //     {
    //         int u = Q.front(); // Source = u destination = v
    //         Q.pop();
    //         cout << u << " ";

    //         for (int v : l[u])
    //         {
    //             if (!vis[v])
    //             {
    //                 vis[v] = true;
    //                 Q.push(v);
    //             }
    //         }
    //     }
    //     cout << endl;
    // }
    // DFS Traversal
    // void dfsHelper(int u, vector<bool> &vis) // keep going to first unvisited neighbour
    // {
    //     cout << u << " ";
    //     vis[u] = true;

    //     for (int v : l[u])
    //     {
    //         if (!vis[v])
    //         {
    //             dfsHelper(v, vis);
    //         }
    //     }
    // };

    // void dfs()
    // {
    //     int src = 0;
    //     vector<bool> vis(V, false);
    //     for (int i = 0; i < V; i++) // For connected vertices
    //     {
    //         if (!vis[i])
    //         {
    //             dfsHelper(i, vis);
    //         }
    //     }
    //     cout << endl;
    // }

    // Detecting a Cycle in Undirected Graph using DFS

    // bool isCycleUndirectedDFS(int src, int par, vector<bool> &vis)
    // {
    //     vis[src] = true;
    //     list<int> neigbors = l[src];
    //     for (int v : neigbors)
    //     {
    //         if (!vis[v])
    //         {
    //             if (isCycleUndirectedDFS(v, src, vis))
    //             {
    //                 return true;
    //             }
    //         }
    //         else if (v != par)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // bool isCycle()
    // {
    //     vector<bool> vis(V, false);
    //     for (int i = 0; i < V; i++)
    //     {
    //         if (!vis[0])
    //         {
    //             if (isCycleUndirectedDFS(i, -1, vis))
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // Detecting a Cycle in Undirected Graph using BFS
    // bool isCycleUndirectedBFS(int src, vector<bool> &vis)
    // {
    //     queue<pair<int, int>> q;
    //     q.push({src, -1});
    //     vis[src] = true;

    //     while (q.size() > 0)
    //     {
    //         int u = q.front().first;
    //         int parU = q.front().second;
    //         q.pop();

    //         list<int> neighbor = l[u];
    //         for (int v : neighbor)
    //         {
    //             if (!vis[v])
    //             {
    //                 q.push({v, u}); // u-----v
    //                 vis[v] = true;
    //             }
    //             else if (v != parU) // cycle condition
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // bool isCycleBFS()
    // {
    //     vector<bool> vis(V, false);
    //     for (int i = 0; i < V; i++)
    //     {
    //         if (!vis[i])
    //         {
    //             if (isCycleUndirectedBFS(i, vis))
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // Detecting a Cycle in Directed Graph using DFS
    // cycle detection
    // bool isCycleDirDFS(int curr, vector<bool> &vis, vector<bool> &recPath)
    // {
    //     vis[curr] = true;
    //     recPath[curr] = true;

    //     for (int v : l[curr])
    //     {
    //         if (!vis[v])
    //         {
    //             if (isCycleDirDFS(v, vis, recPath))
    //             {
    //                 return true;
    //             }
    //         }
    //         else if (recPath[v])
    //         {
    //             return true;
    //         }
    //     }
    //     recPath[curr] = false;
    //     return false;
    // }

    // bool isCycleDFS()
    // {
    //     vector<bool> vis(V, false);
    //     vector<bool> recPath(V, false);
    //     for (int i = 0; i < V; i++)
    //     {
    //         if (!vis[i])
    //         {
    //             if (isCycleDirDFS(i, vis, recPath))
    //             {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // Topplogical Sort using DFS
    void dfs(int curr, vector<bool> &vis, stack<int> &s)
    {
        vis[curr] = true;

        for (int v : l[curr])
        {
            if (!vis[v])
            {
                dfs(v, vis, s);
            }
        }
        s.push(curr);
    }

    void topoSort()
    {
        vector<bool> vis(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, s);
            }
        }
        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 3);

    // g.printAdjList();
    // g.findDegrees();
    // cout << "BFS :";
    // g.bfs();
    // cout << "DFS :";
    // g.dfs();
    // cout << g.isCycleBFS() << endl;
    // cout << g.isCycleDFS() << endl;
    g.topoSort();
    return 0;
}