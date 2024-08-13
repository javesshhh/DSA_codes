// https://www.youtube.com/watch?v=7LjQ57RqgEc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=14
// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode *middleNode(ListNode *head)
    {
        int l = 0;
        ListNode *temp = head;
        while (temp)
        {
            l++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < l / 2; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
};

// slow fast approach

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (true)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};