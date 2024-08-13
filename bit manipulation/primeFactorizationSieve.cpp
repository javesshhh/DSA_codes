// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prime-factorization-using-sieve
// https://www.youtube.com/watch?v=glKWkmKFlMw&list=PLgUwDviBIf0oFON1SRGcMqMIhiZ4EXx_F&index=8&ab_channel=takeUforward

vector<int> findPrimeFactors(int n)
{

    // Write your code here
    vector<int> lpf(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        lpf[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (lpf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (lpf[j] == j)
                    lpf[j] = i;
            }
        }
    }
    vector<int> ans;
    while (n != 1)
    {
        ans.push_back(lpf[n]);
        n = n / lpf[n];
    }
    // sort(ans.begin(),ans.end());
    // No, sorting is not needed because the prime factors are collected in ascending order due to the nature of the sieve and extraction process.
    return ans;
}