#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Graph
{

    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int,int>>[v];

    }

    void addEdge(int u, int v, int wt, bool undir = true)
    {
        l[u].push_back({wt, v});

        if (undir)
        {
            l[v].push_back({wt, u});

        }
cout<<"hello";
        
    }


    int dijkshtra(int src, int dest)
    {
        // Data structure
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;
        // 1.init
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it); //pop

            // iterate over the nbrs of node
            for (auto nbrPair : l[node])
            {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;
                if (distTillNow + currentEdge < dist[nbr])
                {
                    // remove if such a pair already exist

                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    // insert the updated value in th set
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // single source shortest dist to all other node
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << " Dist " << dist[i] << endl;
        }

        // shortest distance to all the other nodes
        return dist[dest];
    }

     void printAdjList(){
        //iterate over all the rows
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            //every element of ith linked list
            for(auto node:l[i]){
                cout<<"("<<node.first<<", "<<node.second<<")";
            }
            cout<<endl;
        }
    }

};
int main()
{
    Graph g(5);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
cout<<"hello";

    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
    cout << g.dijkshtra(0,4)<<endl;
    // g.printAdjList();

    return 0;
}