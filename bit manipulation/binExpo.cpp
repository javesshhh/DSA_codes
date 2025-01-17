// https://leetcode.com/problems/powx-n/description/
// https://www.youtube.com/watch?v=hFWckDXE-K8&list=PLgUwDviBIf0oFON1SRGcMqMIhiZ4EXx_F&index=5&ab_channel=takeUforward

class Solution {
public:
    double myPow(double x, int n) {
        double num = 1;
        long long nn = n;
        if(nn < 0) nn = -nn;
        while(nn>0){
            if(nn%2==1){
                num = num * x;
                nn--;
            }
            else{
                x = x*x;
                nn/=2;
            }
        }
        if(n < 0){
            num = 1.0/num;
        }
        return num;
    }
};