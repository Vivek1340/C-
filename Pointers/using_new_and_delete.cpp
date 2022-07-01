#include<iostream>
using namespace std;


int main(){

    int n;
    cin>>n;
    //Dynamic array

    int *arr = new int[n];
    for(int i=0;i<n;i++){

    arr[i] = i;
    cout<<arr[i] <<" ";
    }

    //delete

   delete [] arr;
   cout<<arr[2];
    return 0;


}