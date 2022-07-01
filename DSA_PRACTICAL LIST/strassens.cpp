#include <iostream>
#define n 2

using namespace std;

void strassensMM(int a[][2], int b[][2], int x)
{
    int p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0;
    cout << "Product Matrix using Strassen's Algo is" << endl;

    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = (a[1][0] + a[1][1]) * b[0][0];
    r = a[0][0] * (b[0][1] - b[1][1]);
    s = a[1][1] * (b[1][0] - b[0][0]);
    t = (a[0][0] + a[0][1]) * b[1][1];
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    cout << p + s - t + v << "\t" << r + t << endl;
    cout << q + s << "\t" << p + r - q + u;
}

int main()
{
    int a[2][2], b[2][2];

    cout << "Enter Matrix A:";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter Matrix B:";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> b[i][j];
        }
    }

    strassensMM(a, b, n);
}