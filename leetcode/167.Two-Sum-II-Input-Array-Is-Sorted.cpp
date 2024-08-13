// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/solutions/3318013/fully-explained-brute-force-to-binary-search-to-two-pointer-optimisation/

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int i=0;
        int j=num.size()-1;
        while(i<=j){
            if(num[i]+num[j]==target){
                return {i+1,j+1};
            }
            else if(num[i]+num[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {-1};
    }
};