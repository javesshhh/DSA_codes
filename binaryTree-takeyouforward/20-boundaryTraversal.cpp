// https://www.youtube.com/watch?v=0ca1nvR0be4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=21&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=boundary-traversal-of-binary-tree

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    void fn(Node *root, vector<int> &ans)                  // preorder traversal for leaf nodes
    {
        // vector<int>ans;
        if (root == nullptr)
        {
            return;
        }
        stack<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.top();
            q.pop();
            if (node->left == nullptr && node->right == nullptr)
                ans.push_back(node->data);
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
        }
        return;
    }

    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        // left boundary
        if (root->left != nullptr || root->right != nullptr) // checking if root is not a leaf node
        {
            Node *node = root;
            ans.push_back(node->data);
            if (node->left) // checking if node->left exist
            {
                node = node->left;
                while (node->left || node->right)
                {
                    ans.push_back(node->data);
                    if (node->left)
                    {
                        node = node->left;
                    }
                    else
                    {
                        node = node->right;
                    }
                }
            }
        }

        // bottom root nodes
        fn(root, ans); // only this function prints leaf nodes

        // right boundary
        if (root->right) // checking if root->right exists
        {
            Node *temp = root->right;
            vector<int> v;
            while (temp->left || temp->right)
            {
                v.push_back(temp->data);
                if (temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }
            reverse(v.begin(), v.end());
            for (auto it : v)
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};

// for code given in video

bool isLeaf(node *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(node *root, vector<int> &res)
{
    node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void addRightBoundary(node *root, vector<int> &res)
{
    node *cur = root->right;
    vector<int> tmp;
    while (cur)
    {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> printBoundary(node *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    addRightBoundary(root, res);
    return res;
}