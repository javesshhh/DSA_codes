// https://www.youtube.com/watch?v=jXu-H7XuClE&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=24&ab_channel=takeUforward
// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *neww = new ListNode(-1), *temp = nullptr;
        temp = neww;
        ListNode *temp1 = list1, *temp2 = list2;
        while (temp1 && temp2)
        {
            if (temp1->val == temp2->val || temp1->val < temp2->val)
            {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else if (temp1->val > temp2->val)
            {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp2)
        {
            temp->next = temp2;
        }
        else if (temp1)
        {
            temp->next = temp1;
        }
        return neww->next;
    }
};