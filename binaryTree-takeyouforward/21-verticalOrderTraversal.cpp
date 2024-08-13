// https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=22&ab_channel=takeUforward
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

// very intuitive solution, logic not from the video
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/3391263/easy-to-understand-solution-without-using-multiset-and-queue-just-using-vector-pair-and-sorting/

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
    map<int, vector<pair<int, int>>> mp;

    static bool cmp(pair<int, int> a, pair<int, int> b) // comparator function
    // https://www.youtube.com/watch?v=_cmbxtxtbNU&ab_channel=CodeUpwithTWINS
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    void fn(int hori, int vert, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        mp[hori].push_back({vert, root->val});
        fn(hori - 1, vert + 1, root->left);
        fn(hori + 1, vert + 1, root->right);
    }

    //                                               can also write above code by iterative traversal
    // void fn(int hori,int vert,Node* root){
    //     // vector<vector<int>> ans;
    //     queue<pair<int,pair<int,Node*>>> q;
    //     if (root == nullptr)
    //     {
    //         return;
    //     }
    //     q.push({hori,{vert,root}});
    //     while (!q.empty())
    //     {
    //             Node *node = q.front().second.second;
    //             int h=q.front().first;
    //             int v=q.front().second.first;
    //             q.pop();

    //             if (node->left != nullptr)
    //             {
    //                 q.push({h-1,{v,node->left}});
    //             }
    //             if (node->right != nullptr)
    //             {
    //                 q.push({h+1,{v+1,node->right}});
    //             }
    //             mp[h].push_back({v, node->data});
    //         // ans.push_back(temp);
    //     }
    //     // return ans;
    // }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        fn(0, 0, root);
        for (auto it : mp)
        {
            sort(it.second.begin(), it.second.end(), cmp); // comparator function
            vector<int> temp;
            for (auto i : it.second)
            {
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};