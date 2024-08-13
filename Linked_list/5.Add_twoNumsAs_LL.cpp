// https://www.youtube.com/watch?v=XmRrGzR6udg&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=6&ab_channel=takeUforward
// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::addTwoNumbers(ListNode *num1, ListNode *num2)
{
    ListNode *temp1 = num1;

    ListNode *temp2 = num2;

    ListNode *dummyNode = new ListNode(-1);

    ListNode *current = dummyNode;

    int carry = 0;

    while (temp1 != nullptr || temp2 != nullptr)
    {

        int sum = carry;

        if (temp1)
            sum += temp1->val;

        if (temp2)
            sum += temp2->val;

        ListNode *newNode = new ListNode(sum % 10);

        carry = sum / 10;

        current->next = newNode;

        current = current->next;

        if (temp1)
            temp1 = temp1->next;

        if (temp2)
            temp2 = temp2->next;
    }

    if (carry == 1)
    {

        ListNode *newNode = new ListNode(carry);

        current->next = newNode;
    }

    return dummyNode->next;
}
