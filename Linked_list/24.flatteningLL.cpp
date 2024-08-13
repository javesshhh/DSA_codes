// https://www.youtube.com/watch?v=ykelywHJWLg&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=28
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */

Node *mergeTwoList(Node *l1, Node *l2)
{
    l1->next = nullptr;
    l2->next = nullptr;
    Node *head = new Node(-1);
    Node *temp = head;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data <= l2->data)
        {
            temp->bottom = l1;
            l1 = l1->bottom;
        }
        else
        {
            temp->bottom = l2;
            l2 = l2->bottom;
        }
        temp = temp->bottom;
    }
    if (l2 == nullptr)
    {
        temp->bottom = l1;
    }
    else if (l1 == nullptr)
    {
        temp->bottom = l2;
    }
    return head->bottom;
}

Node *flatten(Node *root)
{
    if (root == nullptr || root->next == nullptr)
    {
        return root;
    }
    Node *temp = root;
    Node *next = root->next;
    while (next != nullptr)
    {
        Node *mover = next->next;
        temp = mergeTwoList(temp, next);
        next = mover;
    }
    return temp;
}