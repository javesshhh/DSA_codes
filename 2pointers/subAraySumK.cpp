// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
// https://www.youtube.com/watch?v=frf7qxiN2qU&ab_channel=takeUforward

// when elements are only positive

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n)
    {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n)
            sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// when elements are positive negative as well as zero

class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        // Complete the function
        unordered_map<int, int> m;
        int temp = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            temp += arr[i];
            if (m.find(temp) == m.end())
                m[temp] = i;
            if (temp == k)
            {
                ans = max(ans, i + 1);
            }
            else if (m.find(temp - k) != m.end())
            {
                ans = max(ans, i - m[temp - k]);
            }
        }
        return ans;
    }
};