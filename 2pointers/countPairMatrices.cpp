// https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
{
    // Your code goes here
    int ans = 0;
    int i1 = 0;
    int j1 = 0;
    int i2 = n - 1;
    int j2 = n - 1;
    while (j2 >= 0 && i2 >= 0 && i1 < n && j1 < n)
    {
        if (mat1[i1][j1] + mat2[i2][j2] == x)
        {
            ans++;
            if (j1 == n - 1)
            {
                j1 = 0;
                i1++;
            }
            else
            {
                j1++;
            }
        }
        else if (mat1[i1][j1] + mat2[i2][j2] < x)
        {
            if (j1 == n - 1)
            {
                j1 = 0;
                i1++;
            }
            else
            {
                j1++;
            }
        }
        else
        {
            if (j2 == 0)
            {
                i2--;
                j2 = n - 1;
            }
            else
            {
                j2--;
            }
        }
    }
    return ans;
}

//

int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
{
    // Your code goes here
    int start = 0;
    int end = n * n - 1;

    int count = 0;
    while (start < n * n && end >= 0)
    {
        int num1 = mat1[start / n][start % n];
        int num2 = mat2[end / n][end % n];
        if (num1 + num2 == x)
        {
            count++;
            start++;
        }
        else if (num1 + num2 < x)
            start++;
        else
            end--;
    }
    return count;
}