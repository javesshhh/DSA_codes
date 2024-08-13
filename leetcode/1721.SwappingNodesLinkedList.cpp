// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
// https://www.youtube.com/watch?v=PzACfONxUco&ab_channel=CodeFreaks

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *x = head;
        while (--k)
        {
            x = x->next;
        }
        ListNode *end = x;
        ListNode *start = head;
        while (x->next)
        {
            x = x->next;
            start = start->next;
        }
        swap(end->val, start->val);
        return head;
    }
};