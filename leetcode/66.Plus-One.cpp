// https://leetcode.com/problems/plus-one/description/
// https://www.youtube.com/watch?v=lXMy03Mj21M&ab_channel=codeExplainer

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        vector<int>ans(n,0);

        for(int i=n-1;i>=0;i--){
            int digit=digits[i]+carry;
            ans[i]=digit%10;
            carry=digit/10;
        }
        if(carry>0){
            vector<int>ans2(n+1,0);
            // ans.resize(n+1,0);
            for(int i=n-1;i>=0;i--){
                ans2[i+1]=ans[i];
            }
            ans2[0]=carry;
            return ans2;
        }
        return ans;
    }
};