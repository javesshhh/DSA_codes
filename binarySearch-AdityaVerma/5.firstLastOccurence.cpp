#include <bits/stdc++.h>
using namespace std;

int main() {
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        // int mid=(start+end)/2;
        int mid=start + (end-start)/2;

        if(arr[mid]==target){                          //
            res=mid;                                   //
            end=mid-1;                                 // for first occurence
        }

        // if(arr[mid]==target){                          //
        //     res=mid;                                   //
        //     start=mid+1;                               // for last occurence
        // }

        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}