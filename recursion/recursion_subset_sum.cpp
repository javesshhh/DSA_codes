// https://youtu.be/rYkfBRtMJr8
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    void subsets(int i, vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        if (i == n)
        {
            ans.push_back(sum);
            return;
        }
        // sum=sum+arr[i];
        subsets(i+1, arr, n, ans, sum + arr[i]);
        // sum=sum-arr[i];
        subsets(i+1, arr, n, ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        int sum = 0;
        subsets(0, arr, n, ans, sum);
        sort(ans.begin(), ans.end());
        return ans;
    }
};