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

    void inorderTree(tNode *r, vector<int> &v)
    {
        tNode *temp = r;
        if (r == NULL)
            return;
        inorderTree(temp->left, v);
        v.push_back(temp->data);
        inorderTree(temp->right, v);
    }
    void inorderBST(tNode *r, vector<int> v, int &i)
    {
        if (r == NULL)
            return;
        inorderBST(r->left, v, i);
        r->data = v[i];
        ++i;
        inorderBST(r->right, v, i);
    }

    tNode *BTtoBST(tNode *r) // the concept is inorder of BST is in increasing order so if we taking inorder of binary tree and then sort it we get the inorder of binary search tree. So we can just replace all the elements using that inorder only
    {
        vector<int> v;
        int i = 0;
        inorderTree(r, v);
        for (int j = 0; j < v.size(); j++)
            cout << v[j] << " ";
        sort(v.begin(), v.end());
        inorderBST(r, v, i);

        return r;
    }
};

int main(){
     tNode *n = new tNode(12);
    BST tree(n);
    tNode *n1 = new tNode(22);
    tNode *n2 = new tNode(2);
    tNode *n3 = new tNode(10);
    tNode *n4 = new tNode(42);
    tNode *n5 = new tNode(66);
    tree.insertBT(n1, 12, true);
    tree.insertBT(n2, 12, false);
    tree.insertBT(n3, 22, true);
    tree.insertBT(n4, 22, true);
    tree.insertBT(n5, 2, false);

    tree.print2D(tree.root, 5);
    cout<<"BT to BST"<<endl;
    tNode *result = tree.BTtoBST(tree.root);
    tree.print2D(result, 5);

return 0;
}