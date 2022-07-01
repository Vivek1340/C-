#include<iostream>
using namespace std;

//Passed by reference
void print(int a[][100],int n,int m){

    //print

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            cout<<a[i][j];
        }
        cout<<endl;
    }

}

int main(){

    int arr[100][100];
    int n , m;
    cin>>n>>m;

    //take input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

// cout<<&arr[0][0];
// cout<<&arr[0][3];

// cout<<&arr[1][0];

    // print the array
    print(arr,n,m);

    return 0;
}