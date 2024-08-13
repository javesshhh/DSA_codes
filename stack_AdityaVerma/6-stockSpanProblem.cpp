// https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=6&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

// brute

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>ans(n,1);
       for(int i=n-1;i>=0;i--){
           int k=1;
           for(int j=i-1;j>=0;j--){
               if(price[j]>price[i]){
                   break;
               }
               else k++;
           }
           ans[i]=k;
       }
       return ans;
    }
};

//


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>ans(n,1);
       stack<pair<int,int>>s;
       s.push({price[0],0});
       for(int i=1;i<n;i++){
           while(!s.empty() && s.top().first<=price[i]){
               s.pop();
           }
           if(s.empty()){
               ans[i]=-1;
           }
           else{
               ans[i]=s.top().second;
           }
           s.push({price[i],i});
       }
       for(int i=1;i<n;i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};
