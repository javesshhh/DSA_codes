// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &v)
{
    int i = 0;
    int j = 1;
    int n = v.size();
    if (n == 1)
    {
        return 1;
    }
    while (j < n)
    {
        if (v[i] == v[j])
        {
            while (v[i] == v[j])
            {
                j++;
            }
        }
        else
        {
            i++;
            v[i] = v[j];
            j++;
        }
    }
    v.resize(i + 1);
    return v.size();
}

//

int Solution::removeDuplicates(vector<int> &v)
{
    int s = 0;
    int e = 1;
    int n = v.size();
    if (n == 1)
    {
        return 1;
    }
    while (e < n)
    {
        if (v[s] != v[e])
        {
            s++;
            v[s] = v[e];
        }
        e++;
    }
    v.resize(s + 1);
    return v.size();
}

//