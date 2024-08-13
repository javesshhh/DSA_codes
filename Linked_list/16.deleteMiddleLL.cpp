// https://www.youtube.com/watch?v=ePpV-_pfOeI&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=17
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (true)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                break;
            }
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        slow->next = nullptr;
        delete (slow);
        return head;
    }
};