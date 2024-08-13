// https://www.interviewbit.com/problems/subtract/

ListNode *Solution::subtract(ListNode *A)
{

    vector<int> v;

    ListNode *newnode = A;

    ListNode *current = A;

    int sum = 0;

    if (current == NULL)
    {

        return NULL;
    }

    while (current != NULL)
    {

        v.push_back(current->val);

        current = current->next;
    }

    // for handling even case

    for (int i = 0; i < v.size() / 2; i++)
    {

        int sum = v[v.size() - 1 - i] - v[i];

        newnode->val = sum;

        newnode = newnode->next;

        sum = 0;
    }

    return A;
}

// another approach
// reverse 2 times

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *node)
{
    if (node->next == NULL)
    {
        return node;
    }
    else
    {
        ListNode *nNext = node->next;
        ListNode *rev = reverse(nNext);
        nNext->next = node;
        node->next = NULL;
        return rev;
    }
}

int size(ListNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + size(node->next);
}
ListNode *Solution::subtract(ListNode *A)
{
    if (A->next == NULL)
        return A;
    ListNode *curr = A;
    // find half way point
    int n = size(A);
    int c = 0;
    while (curr != NULL && c < (n / 2))
    {
        curr = curr->next;
        c++;
    }

    ListNode *revcurr = reverse(curr);

    ListNode *i, *j;
    i = A;
    j = revcurr;
    while (i != NULL && j != NULL)
    {

        i->val = j->val - i->val;
        if (i->next == curr)
            break;
        i = i->next;
        j = j->next;
    }

    revcurr = reverse(revcurr);

    return A;
}

// another approach
// using recursion

void recur(ListNode *temp, ListNode *&head, int target, int &k)
{
    if (temp == NULL)
        return;

    recur(temp->next, head, target, k);
    if (k <= target)
    {
        k++;
        head->val = temp->val - head->val;
        head = head->next;
    }
}

ListNode *Solution::subtract(ListNode *A)
{

    ListNode *head = A;
    ListNode *temp = A;
    int count = 0;
    while (temp)
        count++, temp = temp->next;
    temp = A;
    int k = 1;
    recur(temp, head, count / 2, k);
    return A;
}