// https://www.youtube.com/watch?v=Z0hwjftStI4&ab_channel=takeUforward
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

bool ispossible(int A[], int N, int M, int mid)
{
    int student_count = 1;
    int page_sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (page_sum + A[i] <= mid)
        {
            page_sum += A[i];
        }
        else
        {
            student_count++;
            if (student_count > M || A[i] > mid)
            {
                return false;
            }
            page_sum = 0;
            page_sum += A[i];
        }
    }
    return true;
}
int findPages(int N, int A[], int M)
{
    // code here
    if (M > N)
        return -1;

    int s = 0;
    int ans = -1;
    int e = accumulate(A, A + N, 0);

    while (s <= e)
    {

        int mid = s + (e - s) / 2;

        if (ispossible(A, N, M, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}