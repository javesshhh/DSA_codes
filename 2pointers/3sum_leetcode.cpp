// https://leetcode.com/problems/3sum/description/
// https://www.youtube.com/watch?v=DhFh8Kw7ymk&ab_channel=takeUforward
// https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/

// approach 1

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n = arr.size();
        set<vector<int>> st;
        // sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = 0 - arr[i] - arr[j];
                if (m.find(temp) != m.end())
                {
                    if (m[temp] != i && m[temp] != j)
                    {
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]); 
                        v.push_back(temp);
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// optimal approach

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        // moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}