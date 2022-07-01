#include<iostream>
using namespace std;

//input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// -1 represent null
//output : 4 2 7 5 1 3 6

class node{
    
    public:
    int data;
    node * left;
    node * right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

//Preorder build of tree ->  root , left , right

node * buildTree(){

    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

// inorder : L N R 

void printInorder(node * root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

int main(){

    node* root = buildTree();
    printInorder(root);


}