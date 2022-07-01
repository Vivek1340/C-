#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define gSpace 10
using namespace std;

class tNode
{
public:
    int data;
    tNode *left;
    tNode *right;
    tNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    tNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    tNode *root;

    BST()
    {
        root = NULL;
    }
    BST(tNode *n)
    {
        root = n;
    }

    void insertNode(tNode *n)
    {
        if (root == NULL)
        {
            root = n;
            cout << "Node added as Root" << endl;
        }
        else if (root != NULL)
        {
            tNode *temp = root;
            while (temp != NULL)
            {
                if (n->data <= temp->data && temp->left == NULL)
                {
                    temp->left = n;
                    cout << "Added Left" << endl;
                    break;
                }
                else if (n->data <= temp->data)
                {
                    temp = temp->left;
                }
                else if (n->data > temp->data && temp->right == NULL)
                {
                    temp->right = n;
                    cout << "Added Right" << endl;
                    break;
                }
                else if (n->data > temp->data)
                {
                    temp = temp->right;
                }
            }
        }
    }

    void insertBT(tNode *n, int val, bool lr)
    {
        if (root == NULL)
            root = n;
        else
        {
            tNode *temp = root;
            while (temp != NULL)
            {
                if (lr && temp->left == NULL)
                {
                    temp->left = n;
                    cout << "Added Left" << endl;
                    break;
                }
                else if (lr)
                {
                    temp = temp->left;
                }
                else if (!lr && temp->right == NULL)
                {
                    temp->right = n;
                    cout << "Added Right" << endl;
                    break;
                }
                else if (!lr)
                {
                    temp = temp->right;
                }
            }
        }
    }

    void searchNode(int val)
    {
        if (root == NULL)
        {
            cout << "Tree is empty! Add values";
        }
        else
        {
            int i = 0;
            tNode *temp = root;
            while (temp != NULL)
            {
                if (temp->data == val)
                {
                    cout << "Node founded at level " << i;
                    break;
                }
                else if (temp->data > val)
                {
                    temp = temp->left;
                    cout << "left";
                }
                else if (temp->data < val)
                {
                    cout << "right";
                    temp = temp->right;
                }

                ++i;
            }
        }
    }

    void preOrderTraversal(tNode *r)
    {
        // cout << "PreOrder Traversal";
        tNode *temp = r;
        if (r == NULL)
        {
            return;
        }
        else
        {
            cout << temp->data << " ";
            preOrderTraversal(temp->left);
            preOrderTraversal(temp->right);
        }
    }
    void inOrderTraversal(tNode *r)
    {
        // cout << "InOrder Traversal";
        tNode *temp = r;
        if (r == NULL)
        {
            return;
        }
        else
        {
            preOrderTraversal(temp->left);
            cout << temp->data << " ";
            preOrderTraversal(temp->right);
        }
    }
    void postOrderTraversal(tNode *r)
    {
        // cout << "PostOrder Traversal";
        tNode *temp = r;
        if (r == NULL)
        {
            return;
        }
        else
        {
            preOrderTraversal(temp->left);
            preOrderTraversal(temp->right);
            cout << temp->data << " ";
        }
    }

    tNode *minValueNode(tNode *n)
    {
        tNode *current = n;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    tNode *deletion(tNode *r, int val)
    {
        if (r == NULL)
        {
            cout << "Empty Trees";
        }
        else
        {
            if (val < r->data)
            {
                r->left = deletion(r->left, val);
            }
            else if (val > r->data)
            {
                r->right = deletion(r->right, val);
            }
            else if (val == r->data)
            {
                if (r->left == NULL)
                {
                    tNode *temp = r->right;
                    // cout << "deleted" << temp->data;
                    delete r;
                    return temp;
                }
                else if (r->right == NULL)
                {
                    tNode *temp = r->left;
                    // cout << "deleted" << temp->data;
                    delete r;
                    return temp;
                }
                else
                {
                    tNode *temp = minValueNode(r->right);
                    r->data = temp->data;
                    r->right = deletion(r->right, temp->data);
                }
            }
        }
    }

    void print2D(tNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += gSpace;
        print2D(r->right, space);
        cout << endl;
        for (int i = gSpace; i < space; i++)
        {
            cout << " ";
        }
        cout << r->data << endl;
        print2D(r->left, space);
    }
};

int main(){
        tNode *n = new tNode(12);
    BST tree(n);
    tNode *n1 = new tNode(41);
    tNode *n2 = new tNode(89);
    tNode *n3 = new tNode(10);
    tNode *n4 = new tNode(42);
    tNode *n5 = new tNode(67);
    tree.insertNode(n1);
    tree.insertNode(n2);
    tree.insertNode(n3);
    tree.insertNode(n4);
    tree.insertNode(n5);

cout<<"PREORDER : "<<endl;
    tree.preOrderTraversal(tree.root);
    cout << endl;
    cout<<"INORDER : "<<endl;
    tree.inOrderTraversal(tree.root);
    cout << endl;
    cout<<"POSTORDER : "<<endl;
    tree.postOrderTraversal(tree.root);
    cout << endl;
    cout<<"BST looks like "<<endl;
    tree.print2D(tree.root, 5);
    cout << endl;
    tree.searchNode(10);

   tNode *deleted = new tNode();
    deleted = tree.deletion(tree.root, 10);
    cout<<endl;
   cout << "Deleted" << deleted->data;
   cout << endl;
   tree.print2D(tree.root, 5);
}