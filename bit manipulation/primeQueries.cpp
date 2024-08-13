// https://www.geeksforgeeks.org/problems/count-primes-in-range1604/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// https://www.youtube.com/watch?v=os82DjD2-MA&list=PLgUwDviBIf0oFON1SRGcMqMIhiZ4EXx_F&index=7&ab_channel=takeUforward
👆👆 for more optimised solution follow video solution

vector<int> sieveOE(int n)
{
    vector<int> vec(n + 1, 1);
    vec[0] = vec[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (vec[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                vec[j] = 0;
            }
        }
    }
    return vec;
}

int countPrimes(int L, int R)
{
    vector<int> prime = sieveOE(R);

    int cnt = 0;

    for (int i = L; i <= R; i++)
    {
        if (prime[i] == 1)
            cnt++;
    }
    return cnt;
}