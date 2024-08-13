// https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
// https://www.youtube.com/watch?v=uiz0IxPCUeU&ab_channel=AdityaVerma

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ele;
    cin>>n;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"enter the element whose lower bound you want to find ";
    cin>>ele;
    int start =0,end=n-1,res;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==ele)
        {
            res=mid;break;
        }
        else if(a[mid]<ele)
        {
            start=mid+1;
        }
        else if(a[mid]>ele)
        {
            res=a[mid];
            end=mid-1;
        }
    }
    cout<<res;
}

// Think about approach given below it may help:
// floor : end pointer after the whole execution of loop,if mid is not exist.
// ceil : start pointer after the whole execution of loop,if mid is not exist.