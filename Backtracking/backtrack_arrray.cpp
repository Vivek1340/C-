#include<iostream>
using namespace std;

void print_array(int *arr,int n){
    for(int i=0;i<n;i++){
            cout<<arr[i];
        }
}

void fillArray(int *arr , int i, int n , int val){
    //base case
    if(i==n){
        //print the array
        print_array(arr , n);
    cout<<endl;
        return;
    }

    //rec case

    arr[i] = val;
    fillArray(arr,i+1,n,val+1);
    //backtracking step

    arr[i] = -1*arr[i];
}

int main(){
    

    int arr[100] = {0};
    int n;
    cin>>n;
    fillArray(arr,0,n,1);
    print_array(arr , n);
}