// https://www.interviewbit.com/problems/reorder-list/
// https://leetcode.com/problems/reorder-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt = NULL;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
ListNode *Solution::reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // ListNode* mid,* slow=head,*fast=head;
    // while(fast && fast->next){
    //     slow=slow->next;
    //     fast=fast->next->next;
    // }
    // mid=slow->next;
    // stack<ListNode*>s;
    // while(mid){
    //     s.push(mid);
    //     mid=mid->next;
    // }
    // ListNode* temp=head;
    // while(temp!=slow){
    //     ListNode* nxt=temp->next;
    //     temp->next=s.top();
    //     s.pop();
    //     temp->next->next=nxt;
    //     temp=nxt;
    // }
    // slow->next=nullptr;
    // return head;
    // step 1 - using slow and fast pointer approach to find the mid of the list
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2 - reverse the second half and split the List into two.
    ListNode *second = reverse(slow->next); // independent list second
    slow->next = NULL;
    ListNode *first = head; // independent list first

    // step 3 - merging the two list
    //  second list can be shorter when LL size is odd
    while (second)
    {
        ListNode *temp1 = first->next;
        ListNode *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
    return head;
}
