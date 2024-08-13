// https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int sum = 0;
    while (i < n && j < n)
    {
        sum += A[j];
        while (i < j && sum >= B)
        {
            sum -= A[i];
            i++;
        }
        if (sum < B)
            cnt += (j - i + 1);     // for counting total subarrays b/w pointers, j-i+1 is used instead of cnt++ bcoz it leaves some subarrays
        j++;
    }
    return cnt;
}
