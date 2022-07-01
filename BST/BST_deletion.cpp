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
        cout<<root->key<<",";
        printInorder(root->right);
    
}
//BSt deletion
Node* findMin(Node* root){
    while(root->left !=NULL){
        root= root->left;
    }
    return root;
}

Node* remove(Node*root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(data < root->key){
        root->left = remove(root->left , data);
    }
    else if(data>root->key){
        root->right = remove(root->right, data);
    }
    else{
        //NO children
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        }
        //1 child
        else if(root->left == NULL ){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        //2 children
        else{
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right,temp->key);
        }

    }
    return root;

}



int main(){

    Node*root = NULL;
    int a[] = {8,3,10,1,6,14,4,7,13};
    for(int x:a){
        root = insert(root,x);
    }
    printInorder(root);
    cout<<endl;
    int data;
    cin>>data;
   root =  remove(root,data);
    cout<<"preorder after deletion:-"<<endl;
    printInorder(root);

    return 0;
}