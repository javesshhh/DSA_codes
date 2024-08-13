// https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &v, int k)
{
    // if(v.size()==1){
    //     return false;
    // }
    int i = 0;
    int j = 0;
    // int diff=0;
    while (j < v.size() && i <= j)
    {
        int diff = v[j] - v[i];
        if (diff == k && i != j)
        {
            return true;
        }
        if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return false;
}
