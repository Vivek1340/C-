#include<iostream>
using namespace std;

void printAllPairs(int arr[],int n){

//print all the pairs ( 2 nested loop)

 for(int i=0;i<n;i++){
        int x= arr[i];
        for(int j=i+1;j<n;j++){
            int y= arr[j];
            cout<<"("<<x<<","<<y<<")"<<" , ";
        }
        cout<<endl;
    }


}

int main(){

    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(int);

    //print all the elements
   printAllPairs(arr,n);

    return 0;
}