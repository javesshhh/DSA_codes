// https://www.youtube.com/watch?v=lIar1skcQYI&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=23
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        if (k == 1)
        {
            return head;
        }
        stack<int> s;
        ListNode *temp = head;
        while (temp)
        {
            ListNode *start = temp;
            for (int i = 0; i < k; i++)
            {
                if (temp == nullptr)
                {
                    return head;
                }
                s.push(temp->val);
                temp = temp->next;
            }
            for (int i = 0; i < k; i++)
            {
                start->val = s.top();
                s.pop();
                start = start->next;
            }
        }
        return head;
    }
};

// another

class Solution {
public:
    void reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }

    ListNode* findKthNode(ListNode* head, int k) {
        int cnt = 1;
        while (cnt < k and head != NULL) {
            head = head->next;
            cnt++;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode != NULL)
                    prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};