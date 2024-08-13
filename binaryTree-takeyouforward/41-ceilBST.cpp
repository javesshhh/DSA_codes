// https://www.youtube.com/watch?v=KSsk8AhdOZA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=42&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-ceil-in-bst

// User function Template for C++

// Function to return the ceil of given number in BST.

void fn(Node *root, int input, int &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data >= input)
    {
        ans = root->data;
        return fn(root->left, input, ans);
    }
    if (root->data < input && root->right)
    {
        return fn(root->right, input, ans);
    }
    // return ans;
}

int findCeil(Node *root, int input)
{
    // Your code here
    if (root == NULL)
        return -1;
    int ans = -1;
    fn(root, input, ans);
    return ans;
}

// another method

// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    // Your code here
    while (root)
    {
        if (root->data == input)
        {
            return root->data;
        }
        else if (root->data > input)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}