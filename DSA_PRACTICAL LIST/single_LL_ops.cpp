#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class SingleLinkedList
{
private:
    Node *head;

public:
    SingleLinkedList()
    {
        head = NULL;
    }
    SingleLinkedList(Node *n)
    {
        head = n;
    }

    void append(Node *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    void prepend(Node *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }
    void insertAtPosition(Node *n, int k)
    { 
        if (head == NULL)
        {
            cout << "Linked List was empty. Placing at first position";
            head = n;
        }
        else
        {
            int l = 0;
            Node *ptr = head;
            while (ptr->next != NULL && l < k - 1)
            {
                ptr = ptr->next;
                l++;
            }
            n->next = ptr->next;
            ptr->next = n;
        }
    }
    void deletionatEnd()
    {
        if (head == NULL)
        {
            cout << "Nothing to Delete";
        }
        else if (head->next == NULL)
        {
            int temp = head->data;
            cout << "Deleted:" << temp << endl;
            head = NULL;
        }
        else
        {
            Node *prevPtr = head;
            Node *currentPtr = head->next;
            while (currentPtr->next != NULL)
            {
                prevPtr = prevPtr->next;
                currentPtr = currentPtr->next;
            }
            prevPtr->next = NULL;
            cout << "Deleted:" << currentPtr->data << endl;
        }
    }
    void deletionAtStart()
    {
        if (head == NULL)
        {
            cout << "Nothing to Delete";
        }
        else if (head->next == NULL)
        {
            int temp = head->data;
            cout << "Deleted:" << temp << endl;
            head = NULL;
        }
        else
        {
            cout << "Deleted:" << head->data << endl;
            head = head->next;
        }
    }
    void deletionAtPosition(int k)
    {
        if (head == NULL)
        {
            cout << "Nothing to Delete";
        }
        else if (head->next == NULL)
        {
            int temp = head->data;
            cout << "Deleted:" << temp << endl;
            head = NULL;
        }
        else
        {
            int l = 1;
            Node *prevPtr = head;
            Node *currentPtr = head->next;
            while (currentPtr->next != NULL && l < k - 1)
            {
                prevPtr = prevPtr->next;
                currentPtr = currentPtr->next;
            }
            prevPtr->next = currentPtr->next;
            cout << "Deleted:" << currentPtr->data << endl;
        }
    }
    void display()
    {
        Node *ptr = head;
        if (head->next == NULL)
            cout  << head->data;
        else
        {
            while (ptr->next != NULL)
            {
                cout  << ptr->data << ",  ";
                ptr = ptr->next;
            }
            cout  << ptr->data << ",";
        }
    }
    void search(int val)
    {
        int l = 0;
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == val)
            {
                cout << "Node:" << ptr->data << " Found at " << l + 1 << " location"<<endl;
                break;
            }
            else if (ptr->data != val)
            {
                ptr = ptr->next;
                ++l;
            }
        }
    }
};

int main(){

    Node *n1 = new Node (5);
    cout<<"Insert a new node : 5"<<endl;
    SingleLinkedList sll (n1);
    
    Node *n2 = new Node(7);
    cout<<"Insert a new node : 7"<<endl;
    sll.append(n2);

    Node *n3 = new Node(1);
    cout<<"Insert a new node : 3"<<endl;
    sll.append(n3);

    Node *n4 = new Node(9);
    cout<<"Insert a new node : 9"<<endl;
    sll.append(n4);

    Node *n5 = new Node(2);
    cout<<"Insert a new node : 2"<<endl;
    sll.append(n5);

    Node *n6 = new Node(8);
    cout<<"Insert a new node : 8 at pos :1"<<endl;

    sll.insertAtPosition(n6 , 1);

    cout<<"Display the remaining node : "<<endl;
    sll.display();

    cout<<endl<<"deletion at end"<<endl;
    sll.deletionatEnd();
    cout<<"Display the remaining node : "<<endl;
    sll.display();
    cout<<endl<<"deletion at start"<<endl;
    sll.deletionAtStart();
    cout<<"Display the remaining node : "<<endl;
    sll.display();
    cout<<endl<<"deltion at position 2"<<endl;
    sll.deletionAtPosition(2);
    cout<<"Display the remaining node : "<<endl;
    sll.display();
    sll.search(1);
    // cout<<"Display the remaining node : "<<endl;
    // sll.display();

    return 0;
}