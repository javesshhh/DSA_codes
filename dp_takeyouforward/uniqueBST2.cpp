// https://leetcode.com/problems/unique-binary-search-trees-ii/description/
// https://www.youtube.com/watch?v=SXU--MPoUe8&ab_channel=codestorywithMIK


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
class Solution {
public:
map<pair<int,int>,vector<TreeNode*>>m;
    vector<TreeNode*> solve(int start,int end){
        if(start>end){
            return {NULL};
        }
        if(start==end){
            TreeNode* root=new TreeNode(start);
            return m[{start,end}]={root};
        }
        if(m.find({start,end})!=m.end()){
            return m[{start,end}];
        }
        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=solve(start,i-1);
            vector<TreeNode*> right=solve(i+1,end);
            for(auto it:left){
                for(auto it2:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=it;
                    root->right=it2;
                    ans.push_back(root);
                }
            }
        }
        return m[{start,end}]=ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};