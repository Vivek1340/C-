#include<iostream>
#include <stack>
#include <algorithm>
#include<math.h>
using namespace std;


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
            else if (precedence(s[i]) == precedence(stack.top()) && s[i] == '^')
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
    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
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


int main(){

    string postfix = "abcd^e-fgh*+^*+i-";
    string s =  postfixToInfix(postfix);
    cout<<"Answer of postfixToInfix is : "<<s<<endl;

    string infix1 = "a+b*(c^d-e)^(f+g*h)-i";
    string stri = infixToPostfix(infix1);
    cout << "Answer of infixToPostfix is: " << stri<<endl;

    string prefix = "*+AB-CD";
    string st =  prefixToInfix(prefix);
    cout<<"Answer of prefixToInfix is : "<<st<<endl;

    string infix = "((A+B)*(C-D))";
    string str =  infixToPrefix(infix);
    cout<<"Answer of infixToPrefix  is : "<<str<<endl;
return 0;

}