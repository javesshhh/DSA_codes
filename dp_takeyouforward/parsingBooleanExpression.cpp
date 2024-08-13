// https://leetcode.com/problems/parsing-a-boolean-expression/description/
// https://youtu.be/lYw86z7Astg

class Solution
{
public:
    bool parseBoolExpr(string s)
    {
        stack<char> st;

        char c = '@';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',' || s[i] == '(')
            {
                continue;
            }
            else if (s[i] == ')')
            {
                bool hasT = false;
                bool hasF = false;
                while (st.top() == 't' || st.top() == 'f')
                {
                    if (st.top() == 't')
                    {
                        hasT = true;
                    }
                    else if (st.top() == 'f')
                    {
                        hasF = true;
                    }
                    st.pop();
                }
                // st.pop();
                c = st.top();
                st.pop();
                if (c == '&')
                {
                    if (hasF == true)
                    {
                        st.push('f');
                    }
                    else if (hasT == true && hasF == false)
                    {
                        st.push('t');
                    }
                }
                else if (c == '|')
                {
                    if (hasT == true)
                    {
                        st.push('t');
                    }
                    else if (hasT == false && hasF == true)
                    {
                        st.push('f');
                    }
                }
                else if (c == '!')
                {
                    if (hasT == true)
                    {
                        st.push('f');
                    }
                    else if (hasF == true)
                    {
                        st.push('t');
                    }
                }
            }
            else
                st.push(s[i]);
        }
        if (st.top() == 't')
        {
            return true;
        }
        // else if(st.top()=='f'){
        return false;
        // }
    }
};