#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;
//BFS AND DFS WITH ADJACENCY MATRIX REPRESENTATION OF GRAPH
vector<vector<int>> graph={{0,1,0,0,1,0},
                            {1,0,0,1,0,0},
                            {1,0,0,1,0,1},
                            {1,0,1,0,0,1},
                            {1,0,0,0,0,0},
                            {0,0,1,0,0,0}};


void dfs(vector<vector<int>> g,int start){
    int v=g.size();
    stack<int>s;
    s.push(start);
    unordered_map<int,int> visited;
    visited[start]=1;
    cout<<"DFS : ";
    while(!s.empty()){
        int curr=s.top();
        s.pop();
        cout<<curr<<" ";
        for(int i=0;i<v;i++){
            if(g[curr][i]==1 && visited[i]!=1){
                s.push(i);
                visited[i]=1;
            }
        }
    }
}

void bfs(vector<vector<int>> g,int start){
    int v=g.size();
    queue<int>q;
    q.push(start);
    unordered_map<int,int> visited;
    visited[start]=1;
     cout<<"BFS : ";
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i=0;i<v;i++){
            if(g[curr][i]==1 && visited[i]!=1){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    dfs(graph,0);
    cout<<endl;    
    bfs(graph,0);
    return 0;
}