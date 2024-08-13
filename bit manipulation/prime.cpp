// https://www.geeksforgeeks.org/problems/prime-number2314/1

int isPrime(int N)
{
    // code here
    int cnt = 0;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            cnt++;
            if (N / i != i)
                cnt++;
        }
    }
    if (cnt == 2)
        return 1;
    return 0;
}