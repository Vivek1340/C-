#include<iostream>
#include "list.h"
using namespace std;

int main(){
    List  l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.insert(2,2);
    l.push_front(5);
   // l.pop_front();

    Node* head1 = l.begin();
    while(head1!=NULL){
        cout<<head1->getData()<<"->";
        head1 = head1->next;
    }
    cout<<endl;

    // cout<<head1;
    // cout<<endl;

   Node*head = l.reverse();
   while(head != NULL){
     cout<<head->getData()<<"->";
     head = head->next;
   }

    // Node * head = l.begin();
    //  while(head!=NULL){
    //    cout<<head->getData()<<"->";
    //    head = head->next;
    //  }
    //  cout<<endl;
    
    //   while(head!=NULL){
    //     cout<<head->getData()<<"->";
    //     head = head->next;
    // }

    // int key;
    // cin>>key;
    //     cout<<"Element Found at "<<l.search(key)<< endl;

    return 0;
}