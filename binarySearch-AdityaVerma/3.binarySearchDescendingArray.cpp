#include <bits/stdc++.h>
using namespace std;

int main() {
    int start=0;
    int end=n-1;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(target<arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}