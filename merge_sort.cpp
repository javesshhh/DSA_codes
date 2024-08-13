#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int arr[N];

void merge(int l, int r, int mid){
    int l_size=mid-l+1;
    // left array with index l to mid
    int larr[l_size];
    int r_size=r-(mid+1)+1;
    // left array with index mid+1 to r
    int rarr[r_size];
    for(int i=0;i<l_size;i++){
        larr[i]=arr[l+i];
    }
    for(int i=0;i<r_size;i++){
        rarr[i]=arr[mid +1+i];
    }
    larr[l_size]=rarr[r_size]=INT_MAX;
    // for reason
    // https://www.youtube.com/watch?v=cWvruDR-hJA&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=27&ab_channel=Luv


    int li=0; // index pointing larr
    int ri=0; // index pointing rarr

    for(int i=l;i<=r;i++){
        if(larr[li]<=rarr[ri]){
            a[i]=larr[li];
            li++;
        }
        else{
            a[i]=rarr[ri];
            ri++;
        }
    }
}

void mergesort(int l, int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r,mid);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    mergesort(0,n-1);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}