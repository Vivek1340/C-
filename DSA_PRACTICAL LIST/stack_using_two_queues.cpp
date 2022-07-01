#include<iostream>
#include<queue>
using namespace std;

class StackUsingTwoQueues
{
    queue<int> q1;
    queue<int> q2;

public:
    void insert(int x)
    {
        int j = 0;
        q1.push(x);

        while (!q2.empty())
        {
            j = q2.front();
            q1.push(j);
            q2.pop();
        }

        q1.swap(q2);
    }

    void display()
    {
        int h = 0;
        while (!q2.empty())
        {
            h = q2.front();
            cout << h << endl;
            q2.pop();
        }
    }
};
int main(){

    StackUsingTwoQueues s;
    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.display();

return 0;
}
