#include<iostream>
using namespace std;

//sort the elements in increasing order
void bubble_sort(int arr[],int n){

    for(int times = 1;times<=n-1;times++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[]={27,13,46,75,1};
    int n = sizeof(arr)/sizeof(int);

    bubble_sort(arr,n);
    cout<<"Sorted array : ";
    for(auto x:arr){
        cout<<x<<",";
    }

    return 0;
}

//-2,3,4,-1,5,-12,6,1,3