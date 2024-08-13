// https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52&ab_channel=takeUforward
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

// simple inorder traversal - TC : O(n+n), SC : O(n+h); h --> height
class Solution
{
    void inorderTraversal(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        // store inorder traversal
        vector<int> arr;
        inorderTraversal(root, arr);

        // 2 pointer approach
        int i = 0, j = arr.size() - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == k)
                return true;
            else if (sum > k)
                j--;
            else
                i++;
        }

        return false;
    }
};

// another

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_set<int> s;
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        if (s.find(k - root->val) != s.end())
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

// another

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator
{
private:
    stack<TreeNode *> st;
    stack<TreeNode *> Revst;
    void helper1(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        return;
    }
    void helper2(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        while (root)
        {
            Revst.push(root);
            root = root->right;
        }
        return;
    }

public:
    TreeNode *node;
    BSTIterator(TreeNode *root)
    {
        node = root;
        helper1(root);
        helper2(root);
    }

    int next()
    {
        TreeNode *a = st.top();
        st.pop();
        if (a->right)
        {
            helper1(a->right);
        }
        return a->val;
    }
    int prev()
    {
        TreeNode *a = Revst.top();
        Revst.pop();
        if (a->left)
        {
            helper2(a->left);
        }
        return a->val;
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator inorder(root);
        BSTIterator Revinorder(root);

        int a = inorder.next();
        int b = Revinorder.prev();
        while (a < b)
        {
            if (a + b < k)
            {
                a = inorder.next();
            }
            else if (a + b > k)
            {
                b = Revinorder.prev();
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};