// https://leetcode.com/problems/pascals-triangle/description/

// https://www.youtube.com/watch?v=bR7mQgwQ_o8&ab_channel=takeUforward

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> v(n);
        for (int i = 1; i <= n; i++)
        {
            int temp = 1;
            v[i - 1].push_back(temp);
            for (int j = 1; j < i; j++)
            {
                temp *= (i - j);
                temp /= j;
                v[i - 1].push_back(temp);
            }
        }
        return v;
    }
};

// striver solution

class Solution
{
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int i = 1; i < row; i++)
        {
            ans = ans * (row - i);
            ans = ans / (i);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};