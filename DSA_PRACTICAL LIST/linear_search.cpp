#include<iostream>
using namespace std;

int linear_search(int arr[],int n, int key){

for(int i=0;i<n;i++){
    //Check if current element matches with the key
    if(arr[i] == key){
        return i;
    }
}
//out of loop
return -1;

}


int main(){

    int arr[]={10,15,12,9,7,6,24,67,6,4};
    int n= sizeof(arr)/sizeof(int);
    int key;
    cout<<"enter the key to be searched"<<endl;
    cin>>key;

    int index = linear_search(arr,n,key);

    if(index != -1){
        cout<<key <<" is present at index "<<index<<endl;
    }
    else{
        cout<<key<<" is NOT found!"<<endl;
    }
    return 0;
}