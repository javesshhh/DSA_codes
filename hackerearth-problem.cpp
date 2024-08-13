// Given 3 positive numbers A, B and C. We make a set which contains numbers that are either multiples of A or B or (A and B) in increasing order.
// We take the C-th number of set and print from C-th number to 0 with a step value of A or B whichever it is multiple of
// and if its a multiple of both, then use step value as LCM(A, B)
// Output format: One line containing values from C-th number to 0 with the corresponding step value

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int cth_num;
    // finding cth value
    for(int i=1;c>0;i++){
    if(i%a==0||i%b==0){
        cth_num=i;        // after getting cth_num count of c reduces by 1
        c--;              // when c=0, we get cth cth_num and loop out
   }
   }

   int lcm;
   // finding lcm of a and b
   for(int i=1;i<=a*b;i++){
       if(i%a==0&&i%b==0){
           lcm=i;
           break;
       }
   }

   int step;
   // finding step value
   if(cth_num%a==0 && cth_num%b==0)
        step=lcm;
    else if(cth_num%a==0){
        step=a;
    }
    else{
        step=b;
    }

    // printing series
    for(int i=cth_num;i>=0;i=i-step){
    cout <<i<<" ";
    }
}