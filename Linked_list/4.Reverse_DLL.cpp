// https://www.youtube.com/watch?v=u3WUW2qe6ww&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=6&ab_channel=takeUforward
// https://www.codingninjas.com/studio/problems/reverse-a-doubly-linked-list_1116098?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/
#include <bits/stdc++.h>
using namespace std;
Node *reverseDLL(Node *head)
{
    // Write your code here
    stack<int> s;
    Node *temp = head;
    while (temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
}

// another approach

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/
#include <bits/stdc++.h>
using namespace std;
Node *reverseDLL(Node *head)
{
    // Write your code here
    if (head->next == NULL)

    {

        return head;
    }

    Node *temp = head;

    Node *back = NULL;

    while (temp != NULL)

    {

        back = temp->prev;

        temp->prev = temp->next;

        temp->next = back;

        temp = temp->prev;
    }

    // head=back->prev;

    return back->prev;
}
