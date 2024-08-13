// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

vector<long long> lcmAndGcd(long long A, long long B)
{
    // code here
    long long pro = A * B;
    long long gcd = 1;
    while (A > 0 && B > 0)
    {
        if (A >= B)
        {
            A %= B;
        }
        else
        {
            B %= A;
        }
    }
    if (A == 0)
    {
        gcd = B;
    }
    else
    {
        gcd = A;
    }
    long long lcm = (pro) / gcd;
    return {lcm, gcd};
}