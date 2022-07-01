
#include<iostream>
using namespace std;

// Time complexity = O(n)
// space complexity = O(n)

int power(int a,int n){
    //base case
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}

// Time complexity = O(log(n))
// space complexity = O(n)

int fastPower(int a, int n){
    if(n==0)
    {
        return 1;
    }
    int subProb = fastPower(a,n/2);
    int subProbsq = subProb*subProb;
    if(n&1){
        return a*subProbsq;
    }
    return subProbsq;
}

int main(){
    int a, n;
    cin>>a;
    cin>>n;

    cout<<power(a,n)<<endl;
    cout<<fastPower(a,n)<<endl;
}