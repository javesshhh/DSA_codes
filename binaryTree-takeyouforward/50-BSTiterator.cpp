// https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52&ab_channel=takeUforward
// https://leetcode.com/problems/binary-search-tree-iterator/description/

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
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *t1 = st.top();
        st.pop();
        TreeNode *t = t1->right;
        while (t)
        {
            st.push(t);
            t = t->left;
        }
        return t1->val;
    }

    bool hasNext()
    {
        if (st.empty())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */