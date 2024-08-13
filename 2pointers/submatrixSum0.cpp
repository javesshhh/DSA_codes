// https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// https://www.youtube.com/watch?v=AQRGNEHVDn8&ab_channel=GeeksforGeeksPractice

vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
{
    int m = a.size();
    int n = a[0].size();
    int left, right, up, down;
    left = right = up = down = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> arr(m, 0);
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                arr[k] += a[k][j];
            }
            unordered_map<long long, int> map;
            map[0] = -1;
            int l = 0, r = 0;
            long long sum = 0;
            for (int k = 0; k < m; k++)
            {
                sum += arr[k];
                if (map.count(sum))
                {
                    if ((k - map[sum]) > (r - l))
                    {
                        l = map[sum] + 1;
                        r = k + 1;
                    }
                }
                else
                {
                    map[sum] = k;
                }
            }
            if ((j - i + 1) * (r - l) > (right - left) * (down - up))
            {
                up = l;
                down = r;
                left = i;
                right = j + 1;
            }
        }
    }
    vector<vector<int>> result;
    for (int i = up; i < down; i++)
    {
        vector<int> arr;
        for (int j = left; j < right; j++)
        {
            arr.push_back(a[i][j]);
        }
        result.push_back(arr);
    }
    return result;
}