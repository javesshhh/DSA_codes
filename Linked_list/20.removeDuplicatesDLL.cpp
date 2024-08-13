// https://www.youtube.com/watch?v=YJKVTnOJXSY&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=21
// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // Your code here
        if (head->next == NULL)
            return head;
        Node *temp = head;
        while (temp)
        {
            Node *curr = temp->next;
            while (curr && (curr->data == temp->data))
                curr = curr->next;
            if (curr)
                curr->prev = temp;
            temp->next = curr;
            temp = curr;
        }
        return head;
    }
};