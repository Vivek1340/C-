#include<iostream>
#include"queue_ll.h"
using namespace std;

int main(){
    Queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
   
    q.pop();
    q.pop();
    q.push(16);
    q.push(17);

   
  while(!q.empty()){
      cout<<q.top()<<endl;
      q.pop();
  }
//   cout<<q.end();
//   q.pop();
    return 0;
}