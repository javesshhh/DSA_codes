// https://www.youtube.com/watch?v=NXOOYYwpbg4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=2&ab_channel=AdityaVerma
// https://www.geeksforgeeks.org/next-greater-element/
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// https://www.interviewbit.com/problems/nextgreater/

// simple brute force

// Simple C++ program to print next greater elements in a given array
#include <iostream>
using namespace std;

/* prints element and NGE pair
for all elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> " << next << endl;
    }
}

// Driver Code
int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}

// using stack (standard problem)

vector<int> Solution::nextGreater(vector<int> &v) {
    int n=v.size();
    vector<int>ans(n,-1);
    stack<int>s;
    s.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && s.top()<=v[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(v[i]);
    }
    return ans;
}
