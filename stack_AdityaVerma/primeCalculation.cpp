// https://www.interviewbit.com/problems/prime-calculations/

// Store the number of prime factors for each number 1 to 1000000 using sieve.

// Now, find the leftmost element in each subarray of size B having maximum number of prime factors which you can get directly using the above precomputation.

// We will use Deque such that the elements in the deque is stored in descending order.
// If there is any element which have greater prime factors than all the previous elements present in deque, we will pop the elements.

// Front value of Deque will contain our answer.

const int maxN = 1000005;
const int mod = 1e9 + 7;

int primes[maxN];
int isPrime[maxN];

void sieve()
{
    for (int i = 2; i * i < maxN; i++)
    {
        if (isPrime[i] == 0)
        { // (isPrime[i] == 0) are prime.
            primes[i] = 1;
            for (int j = 2 * i; j < maxN; j += i)
            {
                isPrime[j] = 1; // (isPrime[i] == 1) are not prime.
                primes[j]++;
            }
        }
    }
}

int Solution::solve(vector<int> &nums, int k)
{
    int n = nums.size();
    sieve();
    long long int sum = 0;
    deque<long long int> q;
    for (int i = 0; i < nums.size(); i++)
    {
        // Remove elements from the front of the deque that are out of the current window
        while (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }
        // Remove elements from the back of the deque while they have fewer prime factors than the current element
        while (!q.empty() && primes[nums[q.back()]] < primes[nums[i]])
        {
            q.pop_back();
        }
        // Add the current element's index to the back of the deque
        q.push_back(i);
        // If the window size is at least k, add the value of the front of the deque to the sum
        if (i >= k - 1)
        {
            sum += nums[q.front()];
            sum %= mod;
        }
    }
    return sum;
}
