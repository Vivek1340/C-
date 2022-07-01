#include<iostream>
using namespace std;


void print(int arr[][4],int n, int m){
//variable
int startRow =0;
int endRow = n-1;
int startCol = 0;
int endCol = m-1;

while(startCol<=endCol){
    for(int row=startRow;row<=endRow;row++){
        cout<<arr[row][endCol]<<" ";

    }

    if(startRow == endRow)
{
    break;
}
else{
    for(int row = endRow;row>=startRow;row--){
        cout<<arr[row][endCol-1]<<" ";
    }
}
    endCol=endCol-2;
}
}



int main(){

    //Print in Reverse wave form
    int arr[][4] = {{1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int n=4,m=4;

    print(arr,n,m);

    return 0;
}
