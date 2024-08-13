// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int rotateIndex = -1;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                rotateIndex = i;
                break;
            }
        }
        return binarySeach(nums, target, 0, rotateIndex) ||
            binarySeach(nums, target, rotateIndex+1, n-1);
    }

    bool binarySeach(vector<int>& nums, int target , int begin, int end){
        while(begin <= end){
            int middle = (begin+end)/2;
            if(nums[middle] > target){
                end = middle -1;
            } else if(nums[middle] < target){
                begin = middle+1;
            } else {
                return true;
            }
        }
        return false;
    }
};