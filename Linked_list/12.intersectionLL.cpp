// https://www.youtube.com/watch?v=0DYoPz2Tpt4&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=13
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> m;
        while (headA)
        {
            m[headA]++;
            headA = headA->next;
        }
        while (headB)
        {
            // m[headB]++;
            // if (m[headB] == 2)
            // {
            //     return headB;
            // }
            if (m.find(headB) != m.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

// another approach

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = 0;
        int l2 = 0;
        ListNode *a = headA;
        ListNode *b = headB;
        while (a)
        {
            l1++;
            a = a->next;
        }
        while (b)
        {
            l2++;
            b = b->next;
        }
        if (l1 > l2)
        {
            while (l1 - l2)
            {
                headA = headA->next;
                l1--;
            }
        }
        if (l1 < l2)
        {
            while (l2 - l1)
            {
                headB = headB->next;
                l2--;
            }
        }
        while (headA)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = a->next;
            b = b->next;
            if (a == b)
            {
                return a;
            }

            if (a == nullptr)
            {
                a = headB;
            }
            if (b == nullptr)
            {
                b = headA;
            }
        }
        return a;
    }
};