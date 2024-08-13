// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode *ret = temp;
    ListNode *nxt = head->next;
    bool c = false;
    while (nxt)
    {
        int d = temp->val;
        while (nxt && nxt->val == d)
        {
            nxt = nxt->next;
        }
        temp->next = nxt;
        temp = temp->next;
        if (nxt)
            nxt = nxt->next;
    }
    return head;
}
