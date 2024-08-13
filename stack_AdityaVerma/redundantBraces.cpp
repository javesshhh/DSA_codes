// https://www.interviewbit.com/problems/redundant-braces/
// https://www.youtube.com/watch?v=K6m7ysIgGko

int Solution::braces(string s)
{
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ')')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() == '(')
            {
                return true;
            }
            else
            {
                int k = 0;
                while (st.top() != '(')
                {
                    st.pop();
                    k++;
                }
                if (k <= 1)
                {
                    return true;
                }
                st.pop();
                st.push('y');   // equivalent output of poped expression
            }
        }
    }
    return false;
}