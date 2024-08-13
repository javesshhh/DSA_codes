// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
// https://www.youtube.com/watch?v=X45c37QMdX0&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=13&ab_channel=AdityaVerma


                               // solution 1

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int start=0;
        int end=n-1;
        char ans=letters[0];
        int ascii=(int)target;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(letters[mid]==target){
                start=mid+1;
            }
            else if(letters[mid]>target){
                ans=letters[mid];
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};

                         // solution 2 using upperbound

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if(it==Letters.end()) return letters[0];
        else return *it;
        // return it == letters.end() ? letters[0] : *it;
    }
};