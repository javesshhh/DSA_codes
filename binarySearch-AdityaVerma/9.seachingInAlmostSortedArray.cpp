// https://www.geeksforgeeks.org/search-almost-sorted-array/
// https://www.youtube.com/watch?v=W3-KgsCVH1U&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=9&ab_channel=AdityaVerma

// just a variation of simple binary search

/*Follow the steps below to implement the idea:

Initialize a variable mid with l+(r-l)/2.
If arr[mid] is equal to x return mid 
Else if arr[mid-1] is equal to x return mid-1 
Else if arr[mid+1] is equal to x return mid+1
If arr[mid] > x recur for search space l to mid-2 else recur for search space mid+2 to r.*/


int nearlySortedArray(vector<int>&arr,int k)

{

    int l=0,h=arr.size()-1,mid;

    while(l<=h&&l>=0&&h<arr.size())

    {

        mid=l+(h-l)/2;

        if(arr[mid]==k)return mid;

        if(mid-1>=0&&arr[mid-1]==k) return mid-1;

        if(mid+1<arr.size()&&arr[mid+1]==k) return mid+1;

        else if(arr[mid-1]>k) h=mid-2;

        else

        l=mid+2;

    }

    return -1;

}