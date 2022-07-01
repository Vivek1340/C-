#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{

    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir = false)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        // iterate over all the rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            // every element of ith linked list
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void topological_sort()
    {

        vector<int> indegree(V, 0);
        // iterate over all the edges to find the right indegree
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        // bfs

        queue<int> q;
        // init the q with nodes having 0 degree
        for (int i = 0; i < V; i++)
        {

            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // start poping
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            // iterate over the  nbrs of this node and reduce thie indegree by 1
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);

    g.topological_sort();

    return 0;
}