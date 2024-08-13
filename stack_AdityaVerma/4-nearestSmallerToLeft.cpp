// https://www.youtube.com/watch?v=85LWui3FlVk&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=4&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1
// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &v) {
    int n=v.size();
    vector<int>ans(n,-1);
    stack<int>s;
    s.push(v[0]);
    for(int i=1;i<n;i++){
        while(!s.empty() && s.top()>=v[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(v[i]);
    }
    return ans;
}
