#include<iostream>
using namespace std;

class Node{
public:
int key;
Node* left;
Node* right;

Node(int key){
this->key = key;
left = right = NULL;
}
};

Node* insert(Node* root , int key){

    if(root == NULL){
        return new Node(key);
    }
    //rec case
    if(key<root->key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }


    return root;

}
void printInorder(Node* root){

    if(root == NULL){
        return ;
    }
    
        printInorder(root->left);
        cout<<root->key;
        printInorder(root->right);
    
}
bool search(Node* root,int data){

    if(root == NULL){
        cout<<"Not found!! ";
        return false;
    }
    if(root->key ==data){
        return true;
    }
    if(data<root->key){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }

}

int main(){

    Node*root = NULL;
    int a[] = {8,3,10,1,6,14,4,7,13};
    for(int x:a){
        root = insert(root,x);
    }
    printInorder(root);
    cout<<endl;
    cout<<search(root,9);

    return 0;
}