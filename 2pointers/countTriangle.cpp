// https://www.interviewbit.com/problems/counting-triangles/
// https://www.youtube.com/watch?v=PqEiJDdt3S4

int Solution::nTriang(vector<int> &A)
{

    int n = A.size(), ctr = 0;

    const int M = 1e9 + 7;

    sort(A.begin(), A.end());

    for (int i = n - 1; i >= 2; i--)
    {

        int l = 0, r = i - 1;

        while (l < r)
        {

            int sum = A[l] + A[r];

            if (sum > A[i])
            {

                ctr = (ctr % M) + ((r - l) % M);

                r--;
            }

            else
                l++;
        }
    }

    return ctr;
}