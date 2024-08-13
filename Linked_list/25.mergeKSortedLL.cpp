// https://www.youtube.com/watch?v=1zktEppsdig&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=26
// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *neww = new ListNode(-1), *temp = nullptr;
        temp = neww;
        ListNode *temp1 = list1, *temp2 = list2;
        while (temp1 && temp2)
        {
            if (temp1->val == temp2->val || temp1->val < temp2->val)
            {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else if (temp1->val > temp2->val)
            {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
            if (temp2)
            {
                temp->next = temp2;
            }
            else if (temp1)
            {
                temp->next = temp1;
            }
        }
        return neww->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            head = merge(head, lists[i]);
        }
        return head;
    }
};

// another

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;

        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        for (auto head : lists)
            if (head != NULL)
                pq.push({head->val, head});

        while (!pq.empty())
        {
            ListNode *minNode = pq.top().second;
            pq.pop();
            if (minNode->next != NULL)
                pq.push({minNode->next->val, minNode->next});

            dummyTail->next = minNode;
            dummyTail = dummyTail->next;
        }
        return dummyHead->next;
    }
};