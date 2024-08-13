// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    int prevmin = INT_MAX;
    int curmin = INT_MAX;
    int prevmax = INT_MIN;
    int curmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > curmax)
        {
            prevmax = curmax;
            curmax = a[i];
        }
        else if (a[i] > prevmax && a[i] != curmax)
        {
            prevmax = a[i];
        }
        if (a[i] < curmin)
        {
            prevmin = curmin;
            curmin = a[i];
        }
        else if (a[i] < prevmin && a[i] != curmin)
        {
            prevmin = a[i];
        }
    }
    vector<int> v;
    v.push_back(prevmax);
    v.push_back(prevmin);

    return v;
}
