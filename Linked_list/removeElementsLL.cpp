// https://leetcode.com/problems/remove-linked-list-elements/description/

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
    ListNode *removeElements(ListNode *head, int k)
    {
        ListNode *zero = new ListNode();
        ListNode *curr = zero;
        while (head)
        {
            if (head->val == k)
            {
                head = head->next;
                curr->next = nullptr;
            }
            else
            {
                curr->next = head;
                curr = head;
                head = head->next;
            }
        }
        return zero->next;
    }
};