// https://leetcode.com/problems/container-with-most-water/

// n2 approach -- TLE

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                water=max(water,(j-i)*min(height[i],height[j]));
            }
        }
        return water;
    }
};


// optimised approach

class Solution {
public:

    int min(int a,int b){
    if (a<b){
        return a;
    }
    return b;
}

int max(int a,int b ){
    if (a>b) {
        return a;
    }
    return b;
}

// https://www.code-recipe.com/post/container-with-most-water

    int maxArea(vector<int>& height) {
        long long int water=0;
        long long int n=height.size();
        long long int l=0;
        long long int r=n-1;
        while(r>l){
            long long int x=min(height[l],height[r])*(r-l);
            water=max(water,x);
            if(height[r]>=height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return water;
    }
};