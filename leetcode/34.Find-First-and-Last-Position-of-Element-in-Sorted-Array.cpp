// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// https://www.youtube.com/watch?v=zr_AoTxzn0Y&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=5&ab_channel=AdityaVerma

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
    int end=n-1;
    int res=-1;
    vector<int>ans;
    while(start<=end){
        // int mid=(start+end)/2;
        int mid=start + (end-start)/2;

        if(nums[mid]==target){                          //
            res=mid;                                   //
            end=mid-1;                                 // for first occurence
        }

        // if(nums[mid]==target){                          //
        //     res=mid;                                   //
        //     start=mid+1;                               // for last occurence
        // }

        else if(target<nums[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    ans.push_back(res);

    start=0;
    end=n-1;
    res=-1;
    while(start<=end){
        // int mid=(start+end)/2;
        int mid=start + (end-start)/2;

        // if(nums[mid]==target){                          //
        //     res=mid;                                   //
        //     end=mid-1;                                 // for first occurence
        // }

        if(nums[mid]==target){                          //
            res=mid;                                   //
            start=mid+1;                               // for last occurence
        }

        else if(target<nums[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    ans.push_back(res);

    return ans;
    }
};