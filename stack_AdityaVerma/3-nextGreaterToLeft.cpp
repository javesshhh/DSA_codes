// https://www.youtube.com/watch?v=T5s96ynzArg&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=3&ab_channel=AdityaVerma

vector<long long> nextLargerElementToLeft(vector<long long> arr, int n)
{
    // Your code here
    vector<long long int> v;
    stack<long long int> s;
    v.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        s.push(arr[i - 1]);
        if (s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else
        {
            while (!s.empty() && s.top() <= arr[i])
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
    // reverse(v.begin(), v.end());
    return v;
}