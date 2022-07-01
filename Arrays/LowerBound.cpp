#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> A, int Val) {
    // your code goes here
    int n  = A.size();
    int s =0;
    int e = n-1;
    int temp = 0;
    while(s<=e){
        int mid = (s+e)/2;
        if(A[mid]>Val){
            e = mid-1;
        } 
        else {
            temp = A[mid];
            s = mid+1;
        }
       
    }  
     return temp;

    
}

int main(){
    vector<int> A = {-1,-1,2,3,5};

    cout<<lowerBound(A,4);

    return 0;
}