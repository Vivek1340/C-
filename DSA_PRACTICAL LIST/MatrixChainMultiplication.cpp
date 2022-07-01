#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int t[100][100];
//top down dp
int MCM(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1)return t[i][j];
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(min>temp);
            min=temp;
    }
    return t[i][j]=min;
}

int main(){
    int arr[]={1,2,3,4};
    memset(t,-1,sizeof(t));
    cout<<"RESULT OF MATRIX CHAIN MULTIPLICATION IS : "<<MCM(arr,1,3);
    return 0;
}