// https://www.youtube.com/watch?v=3kMKYQ2wNIU&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=9
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode *removeLastNode(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        // Find the second last node
        ListNode *second_last = head;
        while (second_last->next->next != NULL)
            second_last = second_last->next;

        // Delete last node
        delete (second_last->next);

        // Change next of second last
        second_last->next = NULL;

        return head;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int tot = 0;
        ListNode *temp = head;
        while (temp)
        {
            tot++;
            temp = temp->next;
        }
        if (n == tot)
        {
            return head->next;
        }
        if (n == 1)
        {
            return removeLastNode(head);
        }
        temp = head;
        ListNode *prev = head;
        int c = 0;
        while (c < tot - n)
        {
            prev = temp;
            temp = temp->next;
            c++;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        return head;
    }
};

// another approach

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
    ListNode *removeLastNode(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        // Find the second last node
        ListNode *second_last = head;
        while (second_last->next->next != NULL)
            second_last = second_last->next;

        // Delete last node
        delete (second_last->next);

        // Change next of second last
        second_last->next = NULL;

        return head;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (n == 1)
        {
            return removeLastNode(head);
        }
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == nullptr)
        {
            return head->next;
        }
        ListNode *bkd = head;
        while (fast->next != nullptr)
        {
            bkd = bkd->next;
            fast = fast->next;
        }
        ListNode *del = bkd->next;
        bkd->next = bkd->next->next;
        delete (del);
        return head;
    }
};