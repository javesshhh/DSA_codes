// https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
// https://www.youtube.com/watch?v=mKluyW4YFvs&ab_channel=AnujBhaiya

class Solution
{
private:
#define ll long long
    int kadane(vector<int> &temp, int n)
    {
        int sum = 0, ans = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            sum += temp[i];
            if (sum > ans)
                ans = sum;
            if (sum < 0)
                sum = 0;
        }
        return ans;
    }

public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        // we need to convert each higher dimension to lower dimension
        int max_sum = -1e8;
        for (int i = 0; i < C; ++i) // went to each column
        {
            vector<int> temp(R, 0);
            for (int j = i; j < C; ++j)
            {
                for (int k = 0; k < R; ++k)
                {
                    temp[k] += M[k][j];
                }
                int sum = kadane(temp, R);
                if (sum > max_sum)
                    max_sum = sum;
            }
        }

        return max_sum;
    }
};