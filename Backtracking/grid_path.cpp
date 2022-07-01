#include<iostream>
using namespace std;

// time complexity = 2^(m+n)
int gridWays(int i,int j,int m,int n){

if(i==m -1 and j==n-1){
    return 1;
}
if(j>=n or i>=m){
    return 0;
}
int ans = gridWays(i+1,j,m,n)+gridWays(i,j+1,m,n);
return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<< gridWays(0,0,m,n);
    return 0;
}


// now it can also be solved in liear time using small mathematical
// knowledge of combination to travesre m *n grid with only right and up movement
// we can say one of the way is if we go far right then far up we will reach out_of_rangedesired loaction it will have 
// n-1 R (right) and m-1 U(up)
// then we can arrange this using compination 
// m-n-2 !/(m-1)!(n-1)! this will give all combination of 
// R and U and each of it will represent a Path