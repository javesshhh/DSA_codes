// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &v)
{
    int i = 2;
    int j = 2;
    int n = v.size();
    if (n <= 2)
    {
        return n;
    }
    while (j < n)
    {
        if (v[j] == v[i - 1] && v[j] == v[i - 2])
        {
            j++;
        }
        else
        {
            v[i] = v[j];
            i++;
            j++;
        }
    }
    v.resize(i + 1);
    return i;
}

//

int Solution::removeDuplicates(vector<int> &v)
{

    int n = v.size();
    if (n <= 2)
    {
        return n;
    }
    int i = 2;
    int j = 2;
    while (j < n)
    {
        if (v[j] != v[i - 2])
        {
            v[i] = v[j];
            i++;
        }

        j++;
    }
    return i;
}