// https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bottom-view-of-binary-tree
// by level order traversal

// Function to return a list containing the bottom view of the given tree.

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> m;
        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *frontNode = temp.first;
            int hd = temp.second;

            m[hd] = frontNode->data;

            if (frontNode->left)
                q.push(make_pair(frontNode->left, hd - 1));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        for (auto i : m)
            ans.push_back(i.second);

        return ans;
    }
};