// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    queue<Node *> pending;
    if (!root)
        return {};
    vector<int> answer;
    pending.push(root);
    while (!pending.empty())
    {
        int len = pending.size();
        int initLen = len;
        while (len--)
        {
            Node *curr = pending.front();
            pending.pop();
            if (curr->left)
                pending.push(curr->left);
            if (curr->right)
                pending.push(curr->right);
            if (len == initLen - 1)
            {
                answer.push_back(curr->data);
            }
        }
    }
    return answer;
}