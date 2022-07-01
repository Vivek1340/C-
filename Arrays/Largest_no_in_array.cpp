#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> arr) {
    int n = arr.size();
    int largest = arr[0];
    for(int i=0;i<n;i++){
        largest = max(largest , arr[i]);
    }
   return largest;  
}

int main(){

    vector<int> arr = {-1,-2,-3,-3,8};

    cout<<largestElement(arr)<<endl;

    return 0;
}