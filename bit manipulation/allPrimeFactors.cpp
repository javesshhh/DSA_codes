// https://www.geeksforgeeks.org/problems/prime-factors5052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Prime-Factors

// https://www.youtube.com/watch?v=LT7XhVdeRyg&list=PLgUwDviBIf0oFON1SRGcMqMIhiZ4EXx_F&index=4&ab_channel=takeUforward

vector<int> AllPrimeFactors(int n)
{
    // Code here
    vector<int> k;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            k.push_back(i);
            while (n % i == 0)
            {

                n /= i;
            }
        }
    }

    if (n != 1)
        k.push_back(n);

    return k;
}