// https://www.youtube.com/watch?v=uT7YI7XbTY8&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=23&ab_channel=takeUforward
// https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0 || head->next == nullptr)
        {
            return head;
        }
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        if (len == k)
        {
            return head;
        }
        else if (k > len)
            k = k % len;
        if (k == 0)
            return head;
        ListNode *last = head;
        while (last->next)
        {
            last = last->next;
        }
        ListNode *end = head;
        ListNode *nxt = nullptr;
        for (int i = 0; i < len - k - 1; i++)
        {
            end = end->next;
        }
        nxt = end->next;
        end->next = nullptr;
        last->next = head;
        return nxt;
    }
};