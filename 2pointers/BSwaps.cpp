// https://www.interviewbit.com/problems/largest-permutation/
// https://www.youtube.com/watch?v=S59TzsKyOkg

vector<int> Solution::solve(vector<int> &A, int B)
{

    int n = A.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {

        mp[A[i]] = i;
    }

    for (int i = 0; i < n && B > 0; i++)
    {

        if (A[i] != n - i)
        {

            int id = mp[n - i];

            B--;

            swap(mp[A[i]], mp[n - i]);
            swap(A[i], A[id]);
        }
    }

    return A;
}