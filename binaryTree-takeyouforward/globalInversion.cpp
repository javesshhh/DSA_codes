// https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1
// https://www.youtube.com/watch?v=G6-P5hm9JN8&t=0s&ab_channel=AkshayAnil
// https://www.youtube.com/watch?v=Ze2wPBsSY9I&ab_channel=AkshayAnil

// n^2 TLE

class Solution
{
public:
    vector<int> inorderTraversal(Node *root)
    {
        stack<Node *> st;
        Node *node = root;
        vector<int> inorder;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
        return inorder;
    }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root)
    {
        // your code goes here
        int cnt = 0;
        vector<int> arr = inorderTraversal(root);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                    cnt++;
            }
        }
        return cnt;
    }
};

// n log n

// Step1 :Inorder

// Step2 : Apply mergeSorting

// Step3 : Count number of swapping...

class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    void merge(vector<int> &nodes, int low, int mid, int high, int &ans)
    {
        int a = mid - low + 1;
        int b = high - mid;
        int arr1[a];
        int arr2[b];
        for (int i = 0; i < a; i++)
            arr1[i] = nodes[low + i];
        for (int i = 0; i < b; i++)
            arr2[i] = nodes[mid + 1 + i];
        int i = 0, j = 0, k = low;
        while (i < a && j < b)
        {
            if (arr1[i] <= arr2[j])
            {
                nodes[k] = arr1[i];
                i++;
            }
            else
            {
                ans += a - i;
                nodes[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < a)
        {
            nodes[k++] = arr1[i++];
        }
        while (j < b)
        {
            nodes[k++] = arr2[j++];
        }
    }
    void mergesort(vector<int> &nodes, int low, int high, int &ans)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergesort(nodes, low, mid, ans);
        mergesort(nodes, mid + 1, high, ans);
        merge(nodes, low, mid, high, ans);
    }
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root)
    {
        // your code goes here
        vector<int> nodes;
        inorder(root, nodes);
        int ans = 0;
        mergesort(nodes, 0, n - 1, ans);
        return ans;
    }
};