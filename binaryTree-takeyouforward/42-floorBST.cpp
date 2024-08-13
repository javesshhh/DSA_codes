// https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=43&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

// Function to search a node in BST.

void fn(Node *root, int x, int &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data == x)
    {
        ans = x;
        return;
    }
    if (root->data < x)
    {
        ans = root->data;
        fn(root->right, x, ans);
    }
    if (root->data > x)
    {
        fn(root->left, x, ans);
    }
}

int floor(Node *root, int x)
{
    // Code here
    if (root == nullptr)
    {
        return -1;
    }
    int ans = -1;
    fn(root, x, ans);
    return ans;
}

// another method

// Function to search a node in BST.

int floor(Node *root, int x)
{
    // Code here
    if (root == nullptr)
    {
        return -1;
    }
    int ans = -1;
    while (root)
    {
        if (root->data == x)
        {
            return x;
        }
        if (root->data < x)
        {
            ans = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}