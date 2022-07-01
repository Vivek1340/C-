#include<iostream>
#include"heap.h"
using namespace std;

int main(){
    Heap h;
    h.push(45);
    h.push(55);
    h.push(40);
    h.push(15);
    h.push(76);
    h.push(35);
    h.push(90);
    h.push(100);
    h.push(44);
    h.push(70);
    h.push(89);
    h.push(4);
    h.push(5);

    h.display();
    h.pop();
    h.pop();
    h.display();
    cout<<endl<<h.top();
    cout<<endl<<h.empty();


    return 0;
}