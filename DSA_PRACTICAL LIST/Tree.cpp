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
    tNode *n1 = new tNode(32);
    tNode *n2 = new tNode(22);
    tNode *n3 = new tNode(60);
    tNode *n4 = new tNode(70);
    g = t.insert(g, n1);
    g = t.insert(g, n2);
    g = t.insert(g, n3);
    g = t.insert(g, n4);
    t.print2D(g, 5);

    // tNode *n = new tNode(12);
    // BST tree(n);
    // tNode *n1 = new tNode(22);
    // tNode *n2 = new tNode(2);
    // tNode *n3 = new tNode(10);
    // tNode *n4 = new tNode(42);
    // tNode *n5 = new tNode(66);
    // tree.insertBT(n1, 12, true);
    // tree.insertBT(n2, 12, false);
    // tree.insertBT(n3, 22, true);
    // tree.insertBT(n4, 22, true);
    // tree.insertBT(n5, 2, false);

    // tree.print2D(tree.root, 5);
    // tNode *result = tree.BTtoBST(tree.root);
    // tree.print2D(result, 5);

    // int option, val;
    //  BST tree;
    // do
    // {

    //     tNode *n = new tNode();

    //     cout << "What operation do you want to perform? "
    //          << " Select Option number. Enter 0 to exit." << endl;
    //     cout << "1. Insert Node" << endl;
    //     cout << "2. Search Node" << endl;
    //     cout << "3. Delete Node" << endl;
    //     cout << "4. Print" << endl;
    //     cout << "5. PreOrder" << endl;
    //     cout << "6. InOrder" << endl;
    //     cout << "7. PostOrder" << endl;
    //     cout << "8. Clear Screen" << endl;
    //     cout << "0. Exit Program" << endl;
    //     cin >> option;

    //     switch (option)
    //     {
    //     case 1:
    //         cout << "INSERT" << endl;
    //         cout << "Enter Value" << endl;
    //         cin >> val;
    //         n->data = val;
    //         tree.insertNode(n);
    //         cout << endl;
    //         break;
    //     case 2:
    //         cout << "SEARCH" << endl;
    //         cout << "ENTER VALUE" << endl;
    //         cin >> val;
    //         tree.searchNode(val);
    //         break;
    //     case 6:
    //         cout << "Inorder" << endl;
    //         tree.inOrderTraversal(tree.root);
    //     default:
    //         break;
    //     }
    // } while (option != 0);

    // tNode *n = new tNode(12);
    // BST tree(n);
    // tNode *n1 = new tNode(22);
    // tNode *n2 = new tNode(2);
    // tNode *n3 = new tNode(10);
    // tNode *n4 = new tNode(42);
    // tNode *n5 = new tNode(66);
    // tree.insertNode(n1);
    // tree.insertNode(n2);
    // tree.insertNode(n3);
    // tree.insertNode(n4);
    // tree.insertNode(n5);

    // tree.preOrderTraversal(tree.root);
    // cout << endl;
    // tree.inOrderTraversal(tree.root);
    // cout << endl;
    // tree.postOrderTraversal(tree.root);
    // cout << endl;
    // tree.print2D(tree.root, 5);
    // cout << endl;
    // tree.searchNode(22);

    // tNode *deleted = new tNode();
    // deleted = tree.deletion(tree.root, 10);
    // cout << "Deleted" << deleted->data;
    // cout << endl;
    // tree.print2D(tree.root, 5);

    return 0;
}