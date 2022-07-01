#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int &y = x;
    y++;

//Both will give 11 as output

    cout<<x<<endl;
    cout<<y<<endl;

    return 0;

}