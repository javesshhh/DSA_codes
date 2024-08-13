// https://www.youtube.com/watch?v=YitR4dQsddE&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=20
// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        Node *left = head;
        Node *right = head;
        while (right->next)
        {
            right = right->next;
        }
        while (left->data < right->data)
        {
            if (left->data + right->data == target)
            {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (left->data + right->data > target)
            {
                right = right->prev;
            }
            else
            {
                left = left->next;
            }
        }
        return ans;
    }
};