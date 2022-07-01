#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Top down dp
int t[101][101];
int knapsack01(int W,int wt[],int val[],int n){
    if(n==0 || W==0)return 0;
    if(t[n][W]!=-1)return t[n][W];    
    if(wt[n-1]<=W){
        return t[n][W]=max(val[n-1]+knapsack01(W-wt[n-1],wt,val,n-1),knapsack01(W,wt,val,n-1));
    }else{
        return t[n][W]=knapsack01(W,wt,val,n-1);
    }
}

int main(){
    int val[]={5,15,60};
    int weight[]={2,1,3};
    int n=sizeof(weight)/sizeof(weight[0]);
    cout<<"WEIGHT "<<"VALUE"<<endl;
    for(int i=0;i<n;i++){
        cout<<weight[i]<<"      "<<val[i]<<endl;
    }
    int W=5;   
    cout<<"Maximum Capacity: "<<W<<endl;
    memset(t,-1,sizeof(t));
    cout<<"MAXIMUM PROFIT: "<<knapsack01(W,weight,val,n);
    return 0;
}