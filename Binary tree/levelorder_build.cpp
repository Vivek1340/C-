#include<iostream>
#include<queue>
using namespace std;

//input 1 : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
//output 1:
// 1 
// 2 4
// 5 7
// 3
// 6

//input 2: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
//output 2 : 
// 1 
// 2 3
// 4 5 6
// 7


class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
     data = d;
     left = right = NULL;
    }
};

node * levelorderBuild(){

    int d;
    cin>>d;

    node* root = new node(d);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node* current = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            current->left = new node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right = new node(c2);
            q.push(current->right);
        }
    }

    return root;
}
void levelorderPrint(node*root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        if(temp == NULL){
            cout<<endl;
            q.pop();
            //insert a new null for the next level

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}


int main(){

    node*root = levelorderBuild();
    levelorderPrint(root);
    
    return 0;
}