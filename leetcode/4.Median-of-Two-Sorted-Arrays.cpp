// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int k=nums1.size()-1;
        if(nums1.size()%2==0){
            return (nums1[k/2] + nums1[k/2 + 1])/2.0; 
        }
        else{
            return (double)nums1[k/2];
        }
    }
};

// for other approaches
// https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/