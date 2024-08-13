// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        if (head->next->next == nullptr)
        {
            if (head->val == head->next->val)
                return nullptr;
            else
            {
                return head;
            }
        }
        ListNode *zero = new ListNode();
        zero->next = head;
        ListNode *curr = head;
        ListNode *prev = zero;
        bool c = false;
        while (curr)
        {
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                c = true;
            }
            if (c)
            {
                prev->next = curr->next;
                c = false;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return zero->next;
    }
};

//

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        if (head->next->next == nullptr)
        {
            if (head->val == head->next->val)
                return nullptr;
            else
            {
                return head;
            }
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while (head != NULL)
        {

            if (head->next != NULL && head->val == head->next->val)
            {

                while (head->next != NULL && head->val == head->next->val)
                    head = head->next;

                prev->next = head->next;
            }

            else
                prev = prev->next;

            head = head->next;
        }

        return dummy->next;
    }
};