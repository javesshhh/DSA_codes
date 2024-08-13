#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int nge[n];
    for(int i=0;i<n;i++){
        nge[i]=-1;
    }
    stack<int>st;
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty())
            nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    cout<<endl;
}

// https://www.youtube.com/watch?v=Du881K7Jtk8&ab_channel=takeUforward
// concept

// https://takeuforward.org/data-structure/next-greater-element-using-stack/
// explanation