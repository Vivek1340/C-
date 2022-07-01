#include<iostream>
#include<queue>
using namespace std;

class StackUsingQueue
{
public:
    queue<int> q;

    void insert(int x)
    {
        int temp;
        q.push(x);
        if (q.size() > 1)
        {
            for (int i = 0; i < q.size() - 1; i++)
            {
                temp = q.front();
                q.push(temp);
                q.pop();
            }
        }
    }

    void display()
    {
        int h = 0;
        while (!q.empty())
        {
            h = q.front();
            cout << h << endl;
            q.pop();
        }
    }
};

int main(){

    
    StackUsingQueue s;
    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.display();

    return 0;
}