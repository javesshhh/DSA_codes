// https://www.youtube.com/watch?v=lRY_G-u_8jk&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=11
// https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        ListNode *temp = head;
        while (temp)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        bool c = true;
        while (temp)
        {
            if (s.top() != temp->val)
            {
                c = false;
                break;
            }
            s.pop();
            temp = temp->next;
        }
        return c;
    }
};