//staircase Search of both row and colum sorted 2D Array
#include<iostream>
using namespace std;

pair<int,int> staircaseSearch(int arr[][4],int n,int m,int key){
    
    //later if the element is not present return {-1,-1}

    if(key < arr[0][0] or key > arr[n][m]){
        return {-1,-1};
    }
    //Staircase Seach
    int i = 0;
    int j = m-1;
    while(i<=n-1 and j>=0){
        if(arr[i][j] == key){
            return {i,j};
        }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
    return {-1,-1};

}

int main(){

    //2D Row and column wise sorted Array

    int arr[][4] = {{10,20,30,40},
    {15,25,35,45},
    {27,29,37,48},
    {32,33,39,50}};

    int n=5,m=4;

    pair<int,int> coordinate = staircaseSearch(arr,n,m,29);
    cout<<coordinate.first<<" , "<<coordinate.second<<endl;

    return 0;
}