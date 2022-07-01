#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

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
    
    }

    return stack.top();
}

int main(){
string str = "456*+";
int answer = evaluatePostfix(str);
cout<<"Answer of the postfix expression is : "<<answer;

return 0;

}
