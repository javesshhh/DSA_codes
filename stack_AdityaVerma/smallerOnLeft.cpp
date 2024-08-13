// https://www.youtube.com/watch?v=GJtZDxrPsWc&ab_channel=GeeksforGeeksPractice
// https://practice.geeksforgeeks.org/problems/smaller-on-left20360700/1

// Quick summary
// upper bound return first element which is > value. If not, return end().
// lower bound return first element which is ≥ value. If not, return end().

// Vector contains : 10 20 30 30 50
// ******* lower_bound *********
// lower_bound for element 20 at position : 1
// lower_bound for element 25 at position : 2
// ****** upper_bound ************
// upper_bound for element 30 at position : 4
// upper_bound for element 25 at position : 2

vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    vector<int> v;
    set<int> s;
    v.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        s.insert(arr[i - 1]);
        auto it = s.lower_bound(arr[i]);
        if (it == s.begin())
        {
            v.push_back(-1);
        }
        else
        {
            it--;
            v.push_back(*it);
        }
    }
    return v;
}