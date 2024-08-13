// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *revList(ListNode *start)
{
    ListNode *current = start;
    ListNode *prv = nullptr;
    while (current != nullptr)
    {
        ListNode *newNode = current->next;
        current->next = prv;
        prv = current;
        current = newNode;
    }
    return prv;
}
ListNode *Solution::reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr || left == right)
    {
        return head;
    }
    ListNode *current = head;
    ListNode *prv = nullptr;
    int count = 1;
    while (count != left)
    {
        prv = current;
        current = current->next;
        count++;
    }
    ListNode *start = current;
    while (count != right)
    {
        current = current->next;
        count++;
    }
    ListNode *endTurm = current->next;
    current->next = nullptr;
    ListNode *rev = revList(start);
    if (prv != nullptr)
    {
        prv->next = rev;
    }
    else
    {
        head = rev;
    }
    current = rev;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = endTurm;
    return head;
}
