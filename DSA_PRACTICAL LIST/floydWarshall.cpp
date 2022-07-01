#include <iostream>
#include <bits/stdc++.h>
#define v 6
using namespace std;

void floydWarshall(int arr[][v])
{
    int dist[v][v];
    for (int i = 0; i < v; i++) // copying the values in a shortest distance array
    {
        for (int j = 0; j < v; j++)
            dist[i][j] = arr[i][j];
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                else if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "Negative Edge Cycle Present";
            return;
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << i << " --> " << j << " : " << (char)236 << "\t";
            else
                cout << i << " --> " << j << " : " << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int graph[v][v] = {{0, 2, 5, INT_MAX, INT_MAX, INT_MAX},
                       {INT_MAX,0, 4, 3, 7, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 3, 5, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                       {INT_MAX, INT_MAX, INT_MAX, 2, 0, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}};

    floydWarshall(graph);
    return 0;
}