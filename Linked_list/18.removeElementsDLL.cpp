// https://www.youtube.com/watch?v=Mh0NH_SD92k&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=19
// https://www.codingninjas.com/studio/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *deleteAllOccurrences(Node *head, int x)
{
    // Write your code here
    if ((head) == nullptr)
    {
        return head;
    }
    if (head->next == nullptr && head->data == x)
        return nullptr;
    while ((head) && (head)->data == x)
    {
        (head) = (head)->next;
        if (head)
            (head)->prev = nullptr;
    }
    Node *temp = head;
    Node *pre = nullptr;
    Node *trash = nullptr;
    Node *nxt = nullptr;
    while ((temp))
    {
        if ((temp)->data == x)
        {
            (pre) = (temp)->prev;
            (nxt) = (temp)->next;
            if ((pre))
                (pre)->next = (nxt);
            if ((nxt))
                (nxt)->prev = (pre);
            (trash) = (temp);
            (temp) = (nxt);
            delete (trash);
            continue;
        }
        (temp) = (temp)->next;
    }
    return head;
}
