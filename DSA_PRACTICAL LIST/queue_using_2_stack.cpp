#include<iostream>
#include<stack>
using namespace std;

class QueueUsingTwoStacks
{
    stack<int> s1;
    stack<int> s2;

public:
    void insert(int x)
    {
        {
            // Move all elements from s1 to s2
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            // Push item into s1
            s1.push(x);

            // Push everything back to s1
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    void display()
    {
        // cout << s2.size() << endl;
        int h = 0;
        while (!s1.empty())
        {
            h = s1.top();
            cout << h << endl;
            s1.pop();
        }
    }
};

int main(){
    QueueUsingTwoStacks q;
    q.insert(5);
    q.insert(10);
    q.insert(15);
    q.display();
    return 0;
}