#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maxSumSubarray(vector<int> A) {
    int n= A.size();
    int largest = INT_MIN;
    int prefix[n] = {0};
    prefix[0] = A[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + A[i];
    }
    int subarraySum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            subarraySum = i>0 ? prefix[j] - prefix[i] : prefix[j];
            largest = max(largest , subarraySum);
        }
    }
    
    return largest;
     
}
int main(){
    vector<int>A = {-1};
    cout<<maxSumSubarray(A);

    return 0;
}