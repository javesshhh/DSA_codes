// https://www.youtube.com/watch?v=nc1AYFyvOR4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=5&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

// User function Template for C++

class Solution
{

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        // Your code goes here
        vector<int> v;
        stack<int> s;
        v.push_back(-1);
        for (int i = n - 2; i >= 0; i--)
        {
            s.push(arr[i + 1]);
            if (s.top() < arr[i])
            {
                v.push_back(s.top());
            }
            else
            {
                while (!s.empty() && s.top() >= arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                {
                    v.push_back(-1);
                }
                else
                    v.push_back(s.top());
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};