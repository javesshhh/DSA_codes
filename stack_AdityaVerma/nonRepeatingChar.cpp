// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

string Solution::solve(string s)
{
    string ans = "";
    unordered_map<char, int> m;
    deque<char> q;                     // deque is a cpmbination of stack and queue
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
        q.push_back(s[i]);
        while (!q.empty() && m[q.front()] >= 2)
        {
            q.pop_front();
        }
        if (q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    return ans;
}
