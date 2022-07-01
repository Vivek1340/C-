#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
{

    if (root == NULL)
    {
        return new Node(key);
    }
    // rec case
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}
void printRootToLeafPath(Node *root, vector<int> &path)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL and root->right == NULL)
    {
        // print the vector path
        for (int node : path)
        {
            cout << node << "->";
        }
        cout << root->key << endl;
        return;
    }
    // rec case
    path.push_back(root->key);
    printRootToLeafPath(root->left, path);
    printRootToLeafPath(root->right, path);
    // backtracking

    path.pop_back();
    return;
}

int main()
{

    Node *root = NULL;
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int x : a)
    {
        root = insert(root, x);
    }
    vector<int> path;
    printRootToLeafPath(root,path);

    return 0;
}