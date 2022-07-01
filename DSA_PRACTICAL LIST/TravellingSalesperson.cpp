#include<iostream>
#include<bits/stdc++.h>
#include<vector>

#define V 5
using namespace std;

int travellingSalesperson(int graph[][V],int s){
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
 
    } while (next_permutation(vertex.begin(), vertex.end()));
    return min_path;
}

int main(){
    int graph[][V] = { { 0, 15, 20, 25 },
                       { 15, 0, 40, 30 },
                       { 20, 40, 0, 35 },
                       { 25, 30, 35, 0 } };
    int s = 0;
    cout<<"MINIMUM COST FOR TRAVELLING FROM VERTEX 0: "<<travellingSalesperson(graph,s)<<endl;
    return 0;
}