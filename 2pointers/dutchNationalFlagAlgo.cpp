// https://www.interviewbit.com/problems/sort-by-color/
// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

void Solution::sortColors(vector<int> &A)
{
    int s = 0;
    int e = A.size() - 1;
    int mid = 0;
    while (mid <= e)
    {
        if (A[mid] == 0)
        {
            swap(A[s], A[mid]);
            s++;
            mid++;
        }
        else if (A[mid] == 1)
            mid++;
        else
        {
            swap(A[mid], A[e]);
            e--;
        }
    }
    return;
}
