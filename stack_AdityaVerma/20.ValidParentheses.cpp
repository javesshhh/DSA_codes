// https://www.youtube.com/watch?v=wkDfsKijrZ8&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=6&ab_channel=takeUforward
// https://leetcode.com/problems/valid-parentheses/description/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;
        // bool c=true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i]);
            }
            else
            {
                if (s1.empty())
                {
                    return false;
                }
                else if (s[i] == ')' && s1.top() == '(')
                {
                    s1.pop();
                }
                else if (s[i] == '}' && s1.top() == '{')
                {
                    s1.pop();
                }
                else if (s[i] == ']' && s1.top() == '[')
                {
                    s1.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};