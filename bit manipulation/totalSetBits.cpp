// https://www.interviewbit.com/problems/count-total-set-bits/
// https://www.youtube.com/watch?v=uwOz378g3ew&ab_channel=codestorywithMIK

// n log n

const int mod=1e9+7;
int Solution::solve(int A) {
    long long int ans=0;
    for(long long i=1;i<=A;i++){
        long long int k=i;
        long long int temp=0;
        while(k){
            k=k & (k-1);
            temp++;
        }
        ans+=temp%mod;
        ans=ans%mod;
    }
    return ans%mod;
}

// o(n)

const int mod=1e9+7;
int Solution::solve(int A) {
    unordered_map<int,int>m;
    m[0]=0;
    int ans=0;
    for(int i=1;i<=A;i++){
        if(i%2==1){
            m[i]=m[i/2]+1;
            ans+=m[i];
            ans=ans%mod;
        }
        else{
            m[i]=m[i/2];
            ans+=m[i];
            ans=ans%mod;
        }
    }
    return ans%mod;
}

