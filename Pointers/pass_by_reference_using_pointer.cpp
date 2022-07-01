#include<iostream>
using namespace std;

void watchVideo(int * viewptr){

    *viewptr = *viewptr+1;

}

int main(){
    int views = 100;
    watchVideo(&views);

    cout<<views <<endl;

    return 0; 
}