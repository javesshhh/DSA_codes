// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string s)
{
    deque<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '/')
            continue;
        else if (s[i] == '.' && s[i + 1] != '.')
            continue;
        else if (s[i] == '.' && s[i + 1] == '.')
        {
            if (st.empty())
                continue;
            st.pop_back();
        }
        else
        {
            string temp = "";
            while (i < s.length() && s[i] >= 'a' && s[i] <= 'z')
            {
                temp += s[i];
                i++;
            }
            st.push_back(temp);
        }
    }
    if (st.empty())
        return "/";
    string ans = "";
    while (!st.empty())
    {
        ans += '/';
        string temp = st.front();
        st.pop_front();
        ans += temp;
    }
    return ans;
}
