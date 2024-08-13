// https://www.youtube.com/watch?v=gRII7LhdJWc&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=8
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// Function to sort a linked list of 0s, 1s and 2s.
Node *segregate(Node *head)
{

    // Add code here
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *temp = head;
    Node *zero = new Node(0);
    Node *zeropoint = zero;
    Node *one = new Node(1);
    Node *onepoint = one;
    Node *two = new Node(2);
    Node *twopoint = two;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else if (temp->data == 2)
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (onepoint->next != nullptr) ? (onepoint->next) : (twopoint->next);
    one->next = twopoint->next;
    two->next = nullptr;
    Node *newhead = zeropoint->next;
    // zeropoint->next=nullptr;
    // onepoint->next=nullptr;
    // twopoint->next=nullptr;
    return newhead;
}