// https://www.youtube.com/watch?v=I4g1qbkTPus&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=18
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

int countNodesinLoop(struct Node *head)
{
    // Code here
    if (head == nullptr || head->next == nullptr)
        return 0;
    Node *slow = head;
    Node *fast = head;
    // Node* star=nullptr;
    int len = 1;
    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                len++;
                fast = fast->next;
            }
            return len;
        }
    }
    return 0;
}