 #include<iostream>
 #include<queue>
using namespace std;

//input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// -1 represent null
//output :  
//1 
//2 3
//4 5 6
//7
//bottom up approach

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

    node* root = buildTree();
    levelorderPrint(root);

return 0;
}