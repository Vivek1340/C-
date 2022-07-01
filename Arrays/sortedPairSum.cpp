#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
   int a , b;
   int l=0;
   int difference = INT_MAX;
   int r = arr.size();
   while(r>1){
       
       if(abs((arr[r]+arr[l])-x)<difference){
           a=l;
           b=r;
           difference = abs((arr[l]+arr[r])-x);
       }
       
       if(arr[l]+arr[r]>x){
           r--;
       }
       else{
           l++;
       }
   }
   
   return make_pair(arr[a],arr[b]);
}

int main(){

    vector<int> arr{10,22,28,29,30,40};

    cout<<closestSum(arr , 54).first<<endl;
    cout<<closestSum(arr , 54).second;
}