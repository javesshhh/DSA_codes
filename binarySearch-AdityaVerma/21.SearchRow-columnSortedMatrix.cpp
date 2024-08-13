// https://www.youtube.com/watch?v=VS0BcOiKaGI&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=20&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/#practice
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/


// o(n+m) complexity


class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> arr, int n, int m, int x)
    {
        // code here
        int i = 0;
        int j = m - 1;
        while (i >= 0 && i < n && j >= 0 && j < m)
        {
            if (arr[i][j] == x)
            {
                return true;
            }
            else if (arr[i][j] > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};