// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

// A good subarray has exactly k distinct numbers

// at least k distinct number - at least (k-1) distinct numbers

// exactly K problem always can be done (at least k) - (at least k-1)

int totalSubArrays(vector<int> &A, int B)
{
    int count = 0;
    int i = 0;
    map<int, int> mp;

    for (int j = 0; j < A.size(); j++)
    {
        mp[A[j]]++;

        while (mp.size() > B && i <= j)
        {
            mp[A[i]]--;
            if (mp[A[i]] == 0)
            {
                mp.erase(A[i]);
            }
            i++;
        }

        count += (j - i + 1);
    }

    return count;
}

int Solution::solve(vector<int> &A, int B)
{

    // find the no of sub arrays which as at most B element
    // and find no of sub arrays which as at most B-1 element
    // count1-count2=ans;

    return totalSubArrays(A, B) - totalSubArrays(A, B - 1);
}