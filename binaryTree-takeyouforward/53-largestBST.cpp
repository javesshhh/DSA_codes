// https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=54&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/largest-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-bst

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};


class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    NodeValue largestBSTSubtreeHelper(Node *root)
    {
        // An empty tree is a BST of size 0.
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            // It is a BST.
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),
                             left.maxSize + right.maxSize + 1);
        }

        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node *root)
    {
        // Your code here
        return largestBSTSubtreeHelper(root).maxSize;
    }
};