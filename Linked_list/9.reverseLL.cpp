// https://www.youtube.com/watch?v=D2vI2DNJGd8&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=10
// https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode *reverseList(ListNode *head)
    {
        stack<int> s;
        ListNode *temp = head;
        while (temp)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            temp->val = s.top();
            s.pop();
            temp = temp->next;
        }
        return head;
    }
};

// alt

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp)
        {
            ListNode *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
};
