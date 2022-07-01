#include<iostream>
#include<algorithm>

using namespace std;

class Edge{
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}

int findParent(int v,int *parent){
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}

void kruskal(Edge *input,int n,int E){
    //Sort the edge array according to weight
    sort(input,input+E,compare);
    Edge *output=new Edge[n-1];//creating output array
    int *parent=new int[n];//creating parent array
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int i=0,count=0;
    while(count<n-1){
        Edge currEdge=input[i];
        //Finding topmost Parent of vertex source and destination
        int sourceParent=findParent(currEdge.source,parent);
        int destinationParent=findParent(currEdge.dest,parent);
        if(sourceParent!=destinationParent){
            output[count]=currEdge;
            count++;
            parent[sourceParent]=destinationParent;
        }
        i++;
    }

    for(int i=0;i<n-1;i++){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<
        output[i].weight<<endl;
    }
}

int main(){
    int n,E;
    cout<<"Enter number of vertices and Edges"<<endl;
    cin>>n>>E;

    cout<<"Enter souce,destination and weight of the edges"<<endl;
    Edge *input=new Edge[E];
    for(int i=0;i<E;i++){
      int s,d,w;
      cin>>s>>d>>w;
      input[i].source=s;
      input[i].dest=d;
      input[i].weight=w;
    }

    cout<<"Minimum spanning tree for the graph is"<<endl<<"s d w"
    <<endl;
    kruskal(input,n,E);
    return 0;
}