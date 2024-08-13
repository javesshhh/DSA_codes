// https://www.interviewbit.com/problems/numrange/

int count(vector<int> &A, int k)
{
    int n = A.size();
    int i = 0, j = 0;
    int cnt = 0;
    int sum = 0;
    while (j < n)
    {
        sum += A[j];
        while (sum > k)
        {
            sum = sum - A[i];
            i++;
        }
        cnt += j - i + 1;
        j++;
    }
    return cnt;
}
int Solution::numRange(vector<int> &A, int B, int C)
{
    if (C == 0)
        return 0;
    return count(A, C) - count(A, B - 1);
}