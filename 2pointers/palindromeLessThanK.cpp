// https://www.interviewbit.com/problems/palindrome-numbers/

bool isPalind(int n)

{

    int num = n;

    int rev = 0;

    while (n > 0)

    {

        int ld = n % 10;

        rev = rev * 10 + ld;

        n /= 10;
    }

    return (rev == num);
}

int Solution::solve(int A, int B, int C)
{

    vector<int> v;

    for (int i = A; i <= B; i++)

    {

        if (isPalind(i))

        {

            v.push_back(i);
        }
    }

    int ans = 0;

    int i = 0, j = 0;

    while (j < v.size())

    {

        if (v[j] - v[i] <= C)

        {

            ans = max(ans, j - i + 1);     // it calculates all possible 2 numbers picked in that subarray range

            j++;
        }

        else

        {

            i++;
        }
    }

    return ans;
}