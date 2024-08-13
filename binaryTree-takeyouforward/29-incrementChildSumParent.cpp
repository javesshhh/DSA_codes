// https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30&ab_channel=takeUforward
// https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
// https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?leftPanelTab=0

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}