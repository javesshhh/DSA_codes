// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

ListNode *Solution::solve(ListNode *A, int B)
{
    ListNode *cur = A, *nxt, *prev = NULL;
    int k = B;
    while (k-- && cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    A->next = nxt;
    k = B;
    A = prev;
    while (k-- && nxt)
    {
        prev = nxt;
        nxt = nxt->next;
    }
    if (nxt)
        prev->next = solve(nxt, B);
    return A;
}