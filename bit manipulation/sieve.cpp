// https://leetcode.com/problems/count-primes/description/
// https://www.youtube.com/watch?v=g5Fuxn_AvSk&list=PLgUwDviBIf0oFON1SRGcMqMIhiZ4EXx_F&index=6&ab_channel=takeUforward

class Solution
{
public:
    int countPrimes(int n)
    {
        // prime no. generation using sieve of eratothons
        vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        // counting prime numbers
        int primeCount = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                primeCount++;
            }
        }
        return primeCount;
    }
};