#include<iostream>
#include<vector>
#include<limits.h>

#define V 6

using namespace std;

int selectMinVertex(vector<int>&value,vector<bool>&set){
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<V;i++){
        if(set[i]==false && value[i]<min){
            vertex=i;
            min=value[i];
        }
    }
    return vertex;
}

void prims(int graph[V][V]){
    int parent[V];// Stores the MST
    vector<int>value(V,INT_MAX); //for relaxation
    vector<bool>set(V,false); //t->vertex is included in the mst
    parent[0]=-1;
    value[0]=0;

    //form mst with v-1 edges
    for(int i=0;i<V-1;i++){
        //set value in the including set true
        int U=selectMinVertex(value,set);//Find the vertex with minimum value in vector value
        set[U]=true;//set value in the including set true

        //Relaxing adjacent vertices
        for(int j=0;j<V;j++){
            //1)edge present from U to j 2)j not included in the mst 3)edge weight is smaller than current weight
            if(graph[U][j]!=0 && set[j]==false && graph[U][j]<value[j]){
                value[j]=graph[U][j];
                parent[j]=U;
            }
        } 
    }
    //print mst
    for(int i=1;i<V;i++){
        cout<<"EDGE: "<<parent[i]<<"->"<<i<<"   wt: "<<graph[parent[i]][i]<<endl;
    }
}


int main(){
    int graph[V][V]={{0,4,6,0,0,0},
                    {4,0,6,3,4,0},
                    {6,6,0,1,0,0},
                    {0,3,1,0,2,3},
                    {0,4,0,2,0,7},
                    {0,0,0,3,7,0}};
    cout<<"Minimum Spanning Tree for the given Graph is: "<<endl;
    prims(graph);
    return 0;
}