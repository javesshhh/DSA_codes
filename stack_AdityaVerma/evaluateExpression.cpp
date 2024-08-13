// https://www.interviewbit.com/problems/evaluate-expression/

#include <bits/stdc++.h>
using namespace std;
int Solution::evalRPN(vector<string> &v)
{
    int n = v.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
        {
            int a, b;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if (v[i] == "+")

                s.push(a + b);

            else if (v[i] == "-")

                s.push(a - b);

            else if (v[i] == "*")

                s.push(a * b);

            else if (v[i] == "/")

                s.push(a / b);
        }
        else
        {
            s.push(stoi(v[i]));
        }
    }
    return s.top();
}
