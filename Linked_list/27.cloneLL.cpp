// https://www.youtube.com/watch?v=q570bKdrnlw&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=28
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        unordered_map<Node *, Node *> old_to_new;

        Node *curr = head;
        while (curr)
        {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }

        return old_to_new[head];
    }
};

// another

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        // step 1
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        // step 2
        Node *itr = head;
        while (itr != NULL)
        {
            if (itr->random != NULL)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        // step 3
        Node *dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node *fast;
        while (itr != NULL)
        {
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};