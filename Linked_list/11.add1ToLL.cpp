// https://www.youtube.com/watch?v=aXQWhbvT3w0&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=12
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// The Intuition is from adding two linkedlists ..

// 1. Reverse the linkedlist

// 2. Take carry as 1 initially and keep on adding to nodes

// 3. If at the end , carry!=0 ,then reverse linked list then create a node and assign it to

//     head node of linked list

// 4. Otherwise Reverse the linkedlist and return the answer

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp)
        {
            Node *nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        int carry = 1;
        head = reverse(head);
        Node *temp = head;
        // Node *prev = nullptr;
        while (head != nullptr)
        {
            // prev = head;
            int sum = head->data + carry;
            carry = sum / 10;
            head->data = sum % 10;
            head = head->next;
        }
        if (carry != 0)
        {
            temp = reverse(temp);
            Node *newnode = new Node(carry);
            newnode->next = temp;
            return newnode;
        }
        return reverse(temp);
    }
};

// recursive

class Solution
{
public:
    int fn(Node *head)
    {
        if (head == nullptr)
        {
            return 1;
        }
        int carry = fn(head->next);
        head->data += carry;
        if (head->data < 10)
        {
            return 0;
        }
        head->data = 0;
        return 1;
    }
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        int carry = fn(head);
        if (carry)
        {
            Node *neww = new Node(carry);
            neww->next = head;
            return neww;
        }
        return head;
    }
};