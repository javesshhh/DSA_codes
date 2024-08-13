// https://www.youtube.com/watch?v=qf6qp7GzD5Q&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=8
// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode *oddEvenList(ListNode *head)
    {
        vector<int> arr;
        ListNode *temp = head;

        if (head == NULL || head->next == NULL)
            return head;
        while (temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            arr.push_back(temp->val);

        temp = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            arr.push_back(temp->val);

        int i = 0;
        temp = head;
        while (temp != NULL)
        {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};

// optimised

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *oddptr = head;
        ListNode *evenptr = head->next;
        ListNode *evenhead = head->next;

        while (evenptr != NULL && evenptr->next != NULL)
        {
            oddptr->next = oddptr->next->next;
            evenptr->next = evenptr->next->next;

            oddptr = oddptr->next;
            evenptr = evenptr->next;
        }

        oddptr->next = evenhead;

        return head;
    }
};