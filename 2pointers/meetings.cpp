// https://www.interviewbit.com/problems/meeting-rooms/
// https://www.youtube.com/watch?v=s8oOsWGHIl4

int Solution::solve(vector<vector<int>> &A)
{
    // 1   18
    //       18 23
    //    15  19
    //    l=0 , r=30
    //    l=5, r=10

    //    l=1 , r=18
    // int ans=INT_MIN;
    // int temp=0;
    // int mn=INT_MAX;
    // int mx=INT_MIN;
    // for(int i=0;i<A.size();i++){
    //     for(int j=0;j<2;j++){
    //         mn=min(mn,A[i][j]);
    //         mx=max(mx,A[i][j]);
    //     }
    // }
    // // cout<<mn<<" "<<mx<<" "<<endl;
    // // return 0;
    // while(mn<=mx){
    //     for(int i=0;i<A.size();i++){
    //         if(mn>=A[i][0] && mn<=A[i][1]) temp++;
    //     }
    //     ans=max(ans,temp);
    //     mn++;
    //     temp=0;
    // }
    // return ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());
    int cnt = 0;
    for (auto it : A)
    {
        if (pq.empty())
        {
            pq.push(it[1]);
            cnt++;
            continue;
        }
        int a = pq.top();
        if (it[0] < a)
        {
            pq.push(it[1]);
            cnt++;
        }
        else
        {
            pq.pop();
            pq.push(it[1]);
        }
    }
    return cnt;
}
