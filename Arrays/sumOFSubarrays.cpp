#include<iostream>
using namespace std;

// find out the largest sum of subarray;
//Brute Force  O(n^3)
int largestSumOfSubarray1(int arr[],int n){

    int largest_sum = 0;
  

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            largest_sum = max(largest_sum,sum);
           
        }
    } 

    return largest_sum;

}

//Prefix Sum Approach  O(n^2)

int largestSumOfSubarray2(int arr[],int n){

    int largest_sum = 0;
    int prefix[n] = {0};
    prefix[0] = arr [0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int subarraySum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
// put a check if subarraysum >largest sum
            largest_sum = max(largest_sum,subarraySum);
           
        }
    } 

    return largest_sum;

}

int main(){

    int arr[]={-2,3,4,-1,5,-12,6,1,3};
    int n= sizeof(arr)/sizeof(int);

    cout<<largestSumOfSubarray2(arr,n);

    return 0;
}