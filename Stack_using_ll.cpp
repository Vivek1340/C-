#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* link;
};
 
struct Node* top;
void push(int data)
{
    struct Node* temp;
    temp = new Node();
 
    // Check if stack  is full.
    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }
 
    temp->data = data;
 
    temp->link = top;
 

    top = temp;
}
 

int isEmpty()
{
    return top == NULL;
}

int peek()
{
     
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}
 

void pop()
{
    struct Node* temp;
 
    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}
void display()
{
    struct Node* temp;

    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->link;
        }
    }
}
int main()
{
    push(11);
    push(20);
    push(3);
    push(45);
    display();
    cout << "\nTop element is "<< peek() << endl;
    pop();
    pop();
 
    display();
    cout << "\nTop element is " << peek() << endl;
          
    return 0;
}