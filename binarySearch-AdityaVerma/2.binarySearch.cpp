#include <bits/stdc++.h>
using namespace std;

int main() {
    int start=0;
    int end=n-1;
    while(start<=end){
        // int mid=(start+end)/2;                      // might cause overflow due to addition of two large values
        int mid=start + (end-start)/2;                 // prevent overflow
        if(arr[mid]==target){
            return mid;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}