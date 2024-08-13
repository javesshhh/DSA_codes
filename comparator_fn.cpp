#include <bits/stdc++.h>
using namespace std;

// bool cmp(int a,int b){
//     if(a>b) return true;  // increasing order
//     else return false;
// }

// bool cmp(int a,int b){
//     if(a<b) return true;  // decreasing order
//     else return false;
// }

// bool cmp(pair<int,int> a,pair<int,int> b){
//     if(a>b) return true;  // increasing order
//     else return false;
// }

// bool cmp(pair<int,int> a,pair<int,int> b){
//     if(a<b) return true;  // decreasing order
//     else return false;
// }

// bool cmp(pair<int,int> a,pair<int,int> b){
//     if(a.first!=b.first){
//         if(a.first>b.first){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//                                      // first element in increasing order and second in dec if first are equal
//     else{
//         if(a.second<b.second){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// }                                     // this is for manual for loop sorting

// bool cmp(pair<int,int> a,pair<int,int> b){
//     if(a.first!=b.first){
//         if(a.first>b.first){
//             return false;
//         }
//         else{
//             return true;
//         }
//     }
//                                      // first element in increasing order and second in dec if first are equal
//     else{
//         if(a.second<b.second){
//             return false;
//         }
//         else{
//             return true;
//         }
//     }
// }
                // so to remember it do it like this
                // js bhi order m chahiye ussi relation ko return krdo


bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
            return a.first<b.first;
    }
                                     // first element in increasing order and second in dec if first are equal
    else{
            return a.second>b.second;
    }
}

int main()
{
    int n;
    cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> a[i];
    // }

    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = i + 1; j < n; ++j)
    //     {
    //         if (a[i] > a[j])
    //         // this will sort in increasing order
    //         // if a[i] < a[j] , then dec order

    //         // so the main element for sorting is this statement
    //         //so we will abstract this operation into another function

    //         {
    //             swap(a[i], a[j]);
    //         }
    //     }
    // }



    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = i + 1; j < n; ++j)
    //     {
    //         if (cmp(a[i],a[j]))
    //         {
    //             swap(a[i], a[j]);
    //         }
    //     }
    // }

    // we can instead use the inbuilt sort comparator fn for this
    sort(a.begin(),a.end(),cmp);
    // by this we got opposite result as we were getting in n2 for loop
    // this is because comparator function takes the return value in opposite fashion



    for (int i = 0; i < n; ++i)
    {
        cout << a[i].first << " "<<a[i].second<<endl;;
    }
}
