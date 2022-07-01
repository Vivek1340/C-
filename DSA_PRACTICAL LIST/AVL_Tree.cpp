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

class AVLTree
{
public:
    tNode *root;
    AVLTree()
    {
        root = NULL;
    }
    // AVLTree(tNode *n)
    // {
    //     root = n;
    // }
    int height(tNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }
    int getBalanceFactor(tNode *n)
    {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }
    tNode *rightRotate(tNode *y)
    {
        tNode *x = y->left;
        tNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    tNode *leftRotate(tNode *x)
    {
        tNode *y = x->right;
        tNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }
    tNode *insert(tNode *r, tNode *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            cout << "Value inserted successfully" << endl;
            return r;
        }

        if (new_node->data < r->data)
        {
            r->left = insert(r->left, new_node);
        }
        else if (new_node->data > r->data)
        {
            r->right = insert(r->right, new_node);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left Left Case
        if (bf > 1 && new_node->data < r->left->data)
            return rightRotate(r);

        // Right Right Case
        if (bf < -1 && new_node->data > r->right->data)
            return leftRotate(r);

        // Left Right Case
        if (bf > 1 && new_node->data > r->left->data)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Left Case
        if (bf < -1 && new_node->data < r->right->data)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;
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
    void preOrderTraversal(tNode *r)
    {
        // cout << "PreOrder Traversal";
        tNode *temp = r;
        if (r == NULL)
        {
            // cout << "YO";
            return;
        }
        else
        {
            cout << temp->data << " ";
            preOrderTraversal(temp->left);
            preOrderTraversal(temp->right);
        }
    }
};

int main()
{

    tNode *n = new tNode(55);
    AVLTree t;
    tNode *g = t.root;
    g = t.insert(g, n);
    tNode *n1 = new tNode(12);
    tNode *n2 = new tNode(22);
    tNode *n3 = new tNode(90);
    tNode *n4 = new tNode(130);
    tNode *n5 = new tNode(67);
    g = t.insert(g, n1);
    g = t.insert(g, n2);
    g = t.insert(g, n3);
    g = t.insert(g, n4);
    g = t.insert(g, n5);
    t.print2D(g, 6);

    return 0;

}