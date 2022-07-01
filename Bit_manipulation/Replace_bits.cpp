#include<iostream>
using namespace std;

//Replace Bits in N by M

// You are given two 32-bit number, N and M, and two bit position i and j.
// write a method to set all bits between i and j in N equal to M.
// m becomes a substring of N locationed at  and starting at j.

void clearBitsInRange(int &n,int i,int j){
    int a = (~0)<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    n = n & mask; 

}
void replaceBits(int &n,int i,int j,int m){
    clearBitsInRange(n,i,j);
    int mask = (m<<i);
    n = n | mask;
}

int main(){
    int n =15;
    int i=1;
    int j=3;
    int m=2;

    replaceBits(n,i,j,m);

    cout<<n<<endl;

    return 0;
}

