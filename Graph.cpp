#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int neigh : l[i])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void findDegrees()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Degree of vertex " << i << "=" << l[i].size() << endl;
        }
    }

    void bfs()
    {
        queue<int> Q;
        vector<bool> vis(V, false);
        Q.push(0);
        vis[0] = true;

        while (Q.size() > 0)
        {
            int u = Q.front(); // Source = u destination = v
            Q.pop();
            cout << u << " ";

            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    // g.addEdge(6, 8);
    // g.printAdjList();
    // g.findDegrees();
    g.bfs();
    return 0;
}