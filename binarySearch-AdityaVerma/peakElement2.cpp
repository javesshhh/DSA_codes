// https://www.youtube.com/watch?v=nGGp5XBzC4g&ab_channel=takeUforward
// https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        int low = 0, high = m - 1; // Binary search range over columns

        while (low <= high)
        {
            int col = low + (high - low) / 2; // Mid column

            int maxi = 0;
            int row = -1;

            // Find maximum value in the current column
            for (int i = 0; i < n; i++)
            {
                if (mat[i][col] > maxi)
                {
                    maxi = mat[i][col];
                    row = i;
                }
            }

            int curr = mat[row][col];
            int left = (col == 0) ? -1 : mat[row][col - 1];
            int right = (col == m - 1) ? -1 : mat[row][col + 1];

            // Check if the current element is a peak
            if (curr > left && curr > right)
            {
                return {row, col};
            }
            else if (curr < left)
            {
                high = col - 1; // Search left half
            }
            else
            {
                low = col + 1; // Search right half
            }
        }

        return {-1, -1}; // No peak found
    }
};