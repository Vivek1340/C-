#include<iostream>
using namespace std;

int getIthBit(int n,int i){
    int mask = (1<<i);
    return (n & mask)>0 ? 1 : 0;
}
void setIthBit(int &n, int i){
    int mask = 1<<i;
    n = n|mask;

}
void clearIthBit(int &n, int i){

    int mask = ~(1<<i);
    n = n & mask;
}
void updateIthBit(int &n,int i,int v){

    clearIthBit(n,i);
    int mask = (v<<i);
    n = n|mask; //sets the right bit

}

void clearLastIBits(int &n , int i){
    int mask = ((~0)<<i);
    n = n&mask;
}

void clearBitsInRange(int &n,int i,int j){
    int a = (~0)<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    n = n & mask; 

}

int main(){

    int n=31;
    int i;
    //cin>>i;

   // cout<<getIthBit(n,i)<<endl;

   //clearIthBit(n,i);

   //setIthBit(n,i);

   //updateIthBit(n,i,0);
   
   //clearLastIBits(n, i);

   clearBitsInRange(n , 1 , 3);
   cout<<n;

    return 0;
}