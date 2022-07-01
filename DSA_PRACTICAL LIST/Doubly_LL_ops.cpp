#include<iostream>
using namespace std;

class dNode
{
public:
    int data;
    dNode *next;
    dNode *prev;
    dNode()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    dNode(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList
{
private:
    dNode *head;

public:
    DoubleLinkedList()
    {
        head = NULL;
    }
    DoubleLinkedList(dNode *n)
    {
        head = n;
    }

    void append(dNode *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            dNode *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
            n->prev = ptr;
        }
    }
    void prepend(dNode *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            dNode *ptr = head;
            ptr->prev = n;
            n->next = head;
            head = n;
        }
    }
    void insertAtPosition(dNode *n, int k)
    {
        if (head == NULL)
        {
            cout << "Linked List was empty. Placing at first position";
            head = n;
        }
        else
        {
            int l = 0;
            dNode *ptr = head;
            while (ptr->next != NULL && l < k - 1)
            {
                ptr = ptr->next;
                l++;
            }
            n->prev = ptr;
            ptr->next->prev = n;
            n->next = ptr->next;
            ptr->next = n;
        }
    }
    void deletionAtEnd()
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
            dNode *prevPtr = head;
            dNode *currentPtr = head->next;
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
            head->prev = NULL;
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
            dNode *prevPtr = head;
            dNode *currentPtr = head->next;
            while (currentPtr->next != NULL && l < k - 1)
            {
                prevPtr = prevPtr->next;
                currentPtr = currentPtr->next;
            }
            prevPtr->next = currentPtr->next;
            currentPtr->next->prev = prevPtr;
            cout << "Deleted:" << currentPtr->data << endl;
        }
    }
    void display()
    {
        dNode *ptr = head;
        if (head->next == NULL)
            cout << "Node: " << head->data;
        else if (head == NULL)
        {
            cout << "Empty List";
        }
        else
        {
            while (ptr->next != NULL)
            {
                cout << "Node:" << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << "Node:" << ptr->data << " ";
        }
    }
    void search(int val)
    {
        int l = 0;
        dNode *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == val)
            {
                cout << "Found at " << l + 1 << " location" << endl;
                cout << "Node:" << ptr->data << " ";
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

    dNode *n1 = new dNode(5);
    cout<<"inserted a node : 5"<<endl;
    DoubleLinkedList dll(n1);
    dNode *n2 = new dNode(8);
      cout<<"inserted a node  : 8 before last node (prepend)"<<endl;
    dll.prepend(n2);
    dNode *n3 = new dNode(12);
      cout<<"inserted a node : 12"<<endl;
    dll.append(n3);
    dNode *n4 = new dNode(16);
      cout<<"inserted a node : 16"<<endl;
    dll.append(n4);
    dNode *n5 = new dNode(20);
      cout<<"inserted a node : 20"<<endl;
    dll.append(n5);
     cout<<endl<<"display all node "<<endl;
    dll.display();
    dNode *n6 = new dNode(22);
      cout<<endl<<"inserted a node : 22 at pos : 2"<<endl;
    dll.insertAtPosition(n6, 2);
     cout<<endl<<"display all node "<<endl;
    dll.display();
  cout<<endl<<"Deleted a node at end"<<endl;
dll.deletionAtEnd();
 cout<<endl<<"display all node "<<endl;
    dll.display();
  cout<<endl<<"Deleted a node at start"<<endl;
  dll.deletionAtStart();
   cout<<endl<<"display all node "<<endl;
    dll.display();
    cout<<endl<<"Deleted a node at pos 2"<<endl;
    dll.deletionAtPosition(2);
     cout<<endl<<"display all node "<<endl;
    dll.display();
    cout<<endl<<"Node 5 is";
    
   dll.search(5);
   cout<<endl<<"display all node "<<endl;
    dll.display();

    return 0;
}