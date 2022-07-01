#include<iostream>
using namespace std;
//Forward Declaration
class List;

class Node{
    int data;
    
    public:
    Node* next; 

    Node(int d):data(d),next(NULL){}

    int getData(){
        return data;
    }
    

    friend class List;
};

class List{
    Node * head;
    Node * tail;

    int searchHelper(Node *start,int key){
        if(start == NULL){
            return -1;
        }
        //value matches
        if(start->data == key){
            return 0;
        }
        //remaining part of the linked list
        int subIdx = searchHelper(start->next , key);
        if(subIdx == -1){
            return -1;
        }
        else{
            return subIdx + 1;
        }
    }
    public:

    List():head(NULL),tail(NULL){}

    Node * begin(){
        return head;
    }

    void push_front(int data){
        if(head == NULL){
            Node * n = new Node(data);
            head = tail = n;
            
        }
        else{
            Node * n =new Node(data);
            n->next = head;
            head = n;
        }
    }
    void push_back(int data){
        if (head == NULL){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    void insert(int data,int pos){
        if(pos==0){
            push_front(data);
            return;
        }
        //otherwise
        Node * temp = head;
        for(int jump =1;jump<=pos-1;jump++){
            temp=temp->next;
        }
        Node * n = new Node(data);
        n->next = temp->next;
        temp->next = n;

    }
    //search operation
    //linaer search

    int search(int key){

        Node*temp = head;
        int idx =0;
        while(temp!=NULL){
            if(temp->data == key){
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;

    }

    //recursively
    int SearchRecursive(int key){
        int idx = searchHelper(head,key);
        return idx;
    }
void pop_front(){
    Node * temp = head;
    cout<<"deleted element : "<<head->data<<endl;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

Node* reverse(){
    Node*c =head;
    Node *p = NULL;
    Node *N;

    while(c!=NULL){
        //save the next node;
        N= c->next;
        //make the current node point to prev
        c->next = p;
        //update p and c an take them 1 step forward
        p =c;
        c = N;
    }
    return head = p;
}

    ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }
};