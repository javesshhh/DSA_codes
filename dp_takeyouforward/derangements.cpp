// https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

Let countDer(n) be count of derangements for n elements. Below is the recursive relation to it.  

countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]

// A Dynamic programming based C++
// program to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
    // Create an array to store
    // counts for subproblems
    int der[n + 1] = {0};

    // Base cases
    der[1] = 0;
    der[2] = 1;

    // Fill der[0..n] in bottom up manner
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] +
                            der[i - 2]);

    // Return result for n
    return der[n];
}

// Driver code
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}
