// https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::partition(ListNode *A, int B)
{
    ListNode *small = new ListNode(0); // Dummy node for the start of the small list
    ListNode *smallTail = small;       // Tail pointer for the small list

    ListNode *big = new ListNode(0); // Dummy node for the start of the big list
    ListNode *bigTail = big;         // Tail pointer for the big list

    while (A != NULL)
    {
        if (A->val < B)
        {
            smallTail->next = A;
            smallTail = smallTail->next;
        }
        else
        {
            bigTail->next = A;
            bigTail = bigTail->next;
        }
        A = A->next;
    }
    // At the end of the loop, both smallTail and bigTail might still be pointing to the old lists
    bigTail->next = NULL;        // Important to terminate the big list
    smallTail->next = big->next; // Connect the small list to the big list

    ListNode *partitionedHead = small->next; // The real head of the partitioned list

    // Cleanup dummy nodes
    delete small;
    delete big;

    return partitionedHead;
}
