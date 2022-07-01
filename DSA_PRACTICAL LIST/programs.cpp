#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

void bubbleSort(int arr[], int size) // biggest first at last
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << "/";
    }
}

void selectionSort(int arr[], int size) // smallest first at starting
{

    for (int i = 0; i < size; i++)
    {
        int s = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[s] > arr[j])
            {
                s = j;
            }
        }
        if (s != i)
        {
            int temp = arr[i];
            arr[i] = arr[s];
            arr[s] = temp;
        }
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << "/";
    }
}

void insertionSort(int arr[], int size) // left subarray for smaller elements
{
    int key = 0;
    int j = 0;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << "/";
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[10];

    while ((i <= m) && (j <= r))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            ++i;
            ++k;
        }
        else
        {
            temp[k] = arr[j];
            ++j;
            ++k;
        }
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        ++i;
        ++k;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        ++j;
        ++k;
    }

    for (int s = l; s <= r; s++)
    {
        arr[s] = temp[s];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++) // here we need s and e as we always dont want it to run from 0
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }
}

void heapSort() {}

void mergeTwoArrays(int a[], int b[], int m, int n)
{
    int *temp;
    int size = m + n;
    temp = new int[size];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            temp[k] = a[i];
            ++i;
            ++k;
        }
        else if (a[i] > b[j])
        {
            temp[k] = b[j];
            ++k;
            ++j;
        }
    }

    while (i < m)
    {
        temp[k] = a[i];
        ++i;
        ++k;
    }
    while (j < n)
    {
        temp[k] = b[j];
        ++j;
        ++k;
    }

    for (int l = 0; l < size; l++)
    {
        cout << temp[l] << "/";
    }
}

class Stack
{
private:
    int size;
    int *arr;
    int top;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;

        else
            return false;
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow";
        }
        else
        {
            ++top;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack UnderFlow";
        }
        else
        {
            int temp = arr[top];
            --top;
            return temp;
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "Stack Underflow";
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << "->";
            }
        }
    }
    void displayTop()
    {
        if (isEmpty())
            cout << "Stack Underflow";
        else
        {
            cout << "Top:" << arr[top];
        }
    }
};

class Queue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full";
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = val;
        }
        else
        {
            ++rear;
            arr[rear] = val;
        }
    }
    int dequeue()
    {
        if (isEmpty())
            cout << "Queue is Empty";
        else
        {
            int temp = arr[front];
            ++front;
            return temp;
        }
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << "->";
        }
    }
};

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
            cout << "Node: " << head->data;
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
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == val)
            {
                cout << "Found at " << l + 1 << " location";
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

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else if (c == '(' || c == ')')
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> stack;
    string postfix = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stack.push(s[i]);
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            postfix = postfix + s[i];
        }
        else if (s[i] == ')')
        {
            while (stack.top() != '(' && !stack.empty())
            {
                char temp = stack.top();
                postfix += temp;
                stack.pop();
            }
            stack.pop();
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            if (stack.empty())
            {
                stack.push(s[i]);
            }
            else if (precedence(s[i]) > precedence(stack.top()))
            {
                stack.push(s[i]);
            }
            else if (precedence(s[i]) == precedence(stack.top() && s[i] == '^'))
            {
                stack.push(s[i]);
            }
            else
            {
                while (!stack.empty() && (precedence(s[i]) <= precedence(stack.top())))
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            }
        }
    }
    return postfix;
}

string infixToPrefix(string s)
{
    stack<char> stack;
    string prefix = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
            s[i] = '(';
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stack.push(s[i]);
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            prefix = prefix + s[i];
        }
        else if (s[i] == ')')
        {
            while ((stack.top() != '(') && (!stack.empty()))
            {
                char temp = stack.top();
                prefix += temp;
                stack.pop();
            }
            if (stack.top() == '(')
            {
                stack.pop();
            }
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            if (stack.empty())
            {
                stack.push(s[i]);
            }
            else if (precedence(s[i]) > precedence(stack.top()))
            {
                stack.push(s[i]);
            }
            else if (precedence(s[i]) == precedence(stack.top() && s[i] == '^'))
            {
                while (precedence(s[i]) == precedence(stack.top() && s[i] == '^'))
                {
                    prefix += stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            }
            else if (precedence(s[i]) == precedence(stack.top()))
            {
                stack.push(s[i]);
            }
            else
            {
                while (!stack.empty() && (precedence(s[i]) < precedence(stack.top())))
                {
                    prefix += stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            }
        }
    }
    while (!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

string postfixToInfix(string s)
{
    stack<string> stack;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string op(1, s[i]); // makes (1) copies of s[i] and makes it a string op, if we do the next line one, its an error at s[i] is a char and cant be assigned to string op
            // string op=s[i];
            stack.push(op);
        }
        else
        {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();
            stack.push("(" + op2 + s[i] + op1 + ")");
        }
    }

    return stack.top();
}

string prefixToInfix(string s)
{
    stack<string> stack;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string op(1, s[i]);
            // string op = prefix[i];
            stack.push(op);
        }
        else
        {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();
            stack.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    return stack.top();
}

int convertToNumber(char c)
{
    int output = 0;
    if (c == '0')
        output = 0;
    else if (c == '1')
        output = 1;
    else if (c == '2')
        output = 2;
    else if (c == '3')
        output = 3;
    else if (c == '4')
        output = 4;
    else if (c == '5')
        output = 5;
    else if (c == '6')
        output = 6;
    else if (c == '7')
        output = 7;
    else if (c == '8')
        output = 8;
    else if (c == '9')
        output = 9;

    return output;
}

int evaluatePostfix(string s)
{
    stack<int> stack;
    int temp = 0;
    int output;
    ;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            temp = convertToNumber(s[i]);
            stack.push(temp);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            int two = stack.top();
            stack.pop();
            int one = stack.top();
            stack.pop();
            if (s[i] == '+')
                output = one + two;
            else if (s[i] == '-')
                output = one - two;
            else if (s[i] == '*')
                output = one * two;
            else if (s[i] == '/')
                output = one / two;
            else if (s[i] == '^')
                output = pow(one, two);

            stack.push(output);
        }
        cout << stack.top();
    }

    return stack.top();
}

int main()
{

    int a[10] = {5, 102, -9, 87, 96, 69, 45, 29, 420, 0};
    int b[7] = {7, 0, 13, 67, 84, 45, 33};
    int aSize = sizeof(a) / sizeof(a[0]);
    int bSize = sizeof(b) / sizeof(b[0]);

    string postfix = "231*+9-";
    int evaluate = evaluatePostfix(postfix);
    cout << "Answer:" << evaluate;

    // int x = 4;
    // char c = '5';
    // cout << endl
    //      << c;
    // int x = (int)c;
    // cout << x;
    // if (x == 53)
    //     cout << "YEs";

    // mergeTwoArrays(a, b, aSize, bSize);

    // Stack st(6);
    // st.push(5);
    // st.push(8);
    // st.display();
    // st.displayTop();

    // Queue q(5);
    // q.enqueue(6);
    // q.enqueue(7);
    // q.display();
    // dNode *n1 = new dNode(5);
    // DoubleLinkedList dll(n1);
    // dNode *n2 = new dNode(8);
    // dll.prepend(n2);
    // dNode *n3 = new dNode(12);
    // dll.append(n3);
    // dNode *n4 = new dNode(16);
    // dll.append(n4);
    // dNode *n5 = new dNode(20);
    // dll.append(n5);
    // dNode *n6 = new dNode(22);
    // dll.insertAtPosition(n6, 2);

    // dll.deletionAtPosition(2);
    // dll.search(5);
    // dll.display();

    // for (int k = 0; k < aSize; k++)
    // {
    //     cout << a[k] << "/";
    // }

    return 0;
}
