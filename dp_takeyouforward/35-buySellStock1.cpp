// https://youtu.be/excAOvwF_Wk
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=-1;
        int n=prices.size();
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>=mini){
                int pro=prices[i]-mini;
                profit=max(profit,pro);
            }
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};