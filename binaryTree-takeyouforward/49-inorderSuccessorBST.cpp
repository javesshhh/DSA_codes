// https://www.youtube.com/watch?v=SXKAD2svfmI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=50&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')

    Node *ans = nullptr;

    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        if (root == nullptr)
        {
            return ans;
        }
        if (root->data > x->data)
        {
            ans = root;
            return inOrderSuccessor(root->left, x);
        }
        if (root->data <= x->data)
        {
            return inOrderSuccessor(root->right, x);
        }
    }
};