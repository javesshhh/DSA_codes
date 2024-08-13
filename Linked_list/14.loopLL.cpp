// https://www.youtube.com/watch?v=wiOo4DC5GGA&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=15
// https://leetcode.com/problems/linked-list-cycle/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> m;
        while (head)
        {
            if (m.find(head) != m.end())
            {
                return true;
            }
            m[head]++;
            head = head->next;
        }
        return false;
    }
};

// another

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};