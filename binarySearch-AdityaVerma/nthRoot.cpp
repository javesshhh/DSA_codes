// https://www.youtube.com/watch?v=rjEJeYCasHs&ab_channel=takeUforward
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

int NthRoot(int n, int m)
{
    // Code here.
    long long low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long nmid = 1;
        for (int i = 0; i < n; i++)
        {
            nmid *= mid;
            if (nmid > m)
                break;
        }
        if (nmid == m)
            return mid;
        if (nmid < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}