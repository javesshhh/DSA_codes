// https://leetcode.com/problems/longest-string-chain/description/

// https://www.youtube.com/watch?v=YY8iBaYcc4g&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=47&ab_channel=takeUforward

#include <bits/stdc++.h>
using namespace std;

// time : n*n*len

bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0;
    int second = 0;

    while (first < s1.size() && second < s2.size())
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }
    if (first == s1.size() && second == s2.size())
        return true;
    else if (first == s1.size() - 1 && second == s2.size())
        return true;
    else
        return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{

    int n = arr.size();

    // sort the array
    auto comp = [](const std::string &s1, const std::string &s2)
    {
        return s1.size() < s2.size();
    }; // lambda function

    sort(arr.begin(), arr.end(), comp);

    vector<int> dp(n, 1);

    int maxi = 1;

    for (int i = 0; i <= n - 1; i++)
    {

        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {

            if (compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
            }
        }

        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

int main()
{

    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << " The length of the longest string chain is : " << longestStrChain(words);
}

// https://www.youtube.com/watch?v=pXG3uE_KqZM&ab_channel=AlgorithmsMadeEasy

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        // Sort on length
        // Time : NlogN
        sort(words.begin(), words.end(), [](string a, string b)
             { return a.length() < b.length(); });
        int res = 0;
        unordered_map<string, int> memo;

        // Iterate on the words
        // TIme : N * Length * Length
        for (string word : words)
        {
            // Put current word in map with default value.
            memo[word] = 1;
            // Time : Length * Length
            for (int i = 0; i < word.length(); i++)
            {
                string current = word;
                current.erase(i, 1); // Time : Length
                // Check if the value for next is already calculated
                if (memo.find(current) != memo.end())
                {
                    // Update the value in map with the maximum possible value
                    memo[word] = max(memo[word], memo[current] + 1);
                }
            }

            res = max(res, memo[word]);
        }

        return res;
    }
};
