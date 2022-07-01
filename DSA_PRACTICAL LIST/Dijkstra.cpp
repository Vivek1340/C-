#include<iostream>
#include<bits/stdc++.h>
#define V 9

using namespace std;

//next minimum distance vetrex
int minDist(int dist[],bool visited[]){
    int min=INT_MAX,minV;
    for(int v=0;v<V;v++){
        if(visited[v]==false && dist[v]<=min){
            min=dist[v];
            minV=v;
        }
    }
    return minV;
}

//function to print solution
void printSol(int dist[]){
    for(int i=0;i<V;i++){
        cout<<i<<" "<< dist[i]<<endl;
    }
}

void dijsktra(int graph[V][V],int start){
    int dist[V];//stores the minimum distance from source to each point
    bool visited[V];//to check if the vertex has already been visired or not

    //Initialisation of ditance and visited array
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[start]=0;
    
    for(int i=0;i<V;i++){
        int u=minDist(dist,visited);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(dist[u]+graph[u][v]<dist[v] && graph[u][v]!=0){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printSol(dist);
}



int main(){

    int graph[V][V]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijsktra(graph,0);
    return 0;
}