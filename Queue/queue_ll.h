
template <typename T>
class Queue;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;

    node(T d) { data = d; }
};

template <typename T>

class Queue
{

    node<T> *front;
    node<T> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int data)
    {
        node<T> *n = new node<T>(data);
        if (rear == NULL)
        {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }
    bool empty()
    {
        return (front==NULL);
    }
    T top()
    {
        return front->data;
    }
    T end()
    {
        return rear->data;
    }
    void pop()
    {
        if (front == NULL)
        {   rear = NULL;
            return;
        }
        node<T> *temp = front;
        front = front->next;

        // if (front == NULL)
        // {
        //     rear = NULL;
        // }
        delete temp;
    }
};