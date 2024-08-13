// https://www.interviewbit.com/problems/majority-element/
// https://www.youtube.com/watch?v=nP_ns3uSh80

int Solution::majorityElement(const vector<int> &A)
{
    int n = A.size();
    int cnt = 0;
    int maj = -1;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            maj = A[i];
            cnt++;
        }
        else if (A[i] == maj)
            cnt++;
        else if (A[i] != maj)
        {
            cnt--;
        }
    }
    int freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == maj)
            freq++;
    }
    if (freq > n / 2)
        return maj;
    else
        return -1;
}
