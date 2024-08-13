// https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=top-view-of-binary-tree

// code not from video logic
// from the logic of previous code and using only top or first from every vertical line

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.

    map<int, vector<pair<int, int>>> mp;

    static bool cmp(pair<int, int> a, pair<int, int> b) // comparator function
    // https://www.youtube.com/watch?v=_cmbxtxtbNU&ab_channel=CodeUpwithTWINS
    {
        // if (a.first == b.first)
        // {
        //     continue;
        // }
        return a.first < b.first;
    }

    void fn(int hori, int vert, Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        mp[hori].push_back({vert, root->data});
        fn(hori - 1, vert + 1, root->left);
        fn(hori + 1, vert + 1, root->right);
    }

    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> ans;
        fn(0, 0, root);
        for (auto it : mp)
        {
            sort(it.second.begin(), it.second.end(), cmp); // comparator function
            // vector<int> temp;
            for (auto i : it.second)
            {
                ans.push_back(i.second);
                break;
            }
            // ans.push_back(temp);
        }
        return ans;
    }
};

// another method using iterative traversal

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int vertical = q.front().second;
            q.pop();
            if (mp.find(vertical) == mp.end()) // just adding first node every vertical
            {
                mp[vertical] = node->data;
            }
            if (node->left)
            {
                q.push({node->left, vertical - 1});
            }
            if (node->right)
            {
                q.push({node->right, vertical + 1});
            }
        }
        vector<int> ans;
        for (auto e : mp)
        {
            ans.push_back(e.second);
        }
        return ans;
    }
};
