// https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
// https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

/*Complete the function below

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

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        // Add your code here
        if (root == nullptr)
        {
            return 0;
        }
        //  int ans=1;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *node = s.top();
            s.pop();
            int left = 0;
            int right = 0;
            if (node->left)
            {
                left = node->left->data;
            }
            if (node->right)
            {
                right = node->right->data;
            }
            if (node->left || node->right)
                if (left + right != node->data)
                {
                    return 0;
                }
            if (node->right)
            {
                s.push(node->right);
            }
            if (node->left)
            {
                s.push(node->left);
            }
        }
        return 1;
    }
};