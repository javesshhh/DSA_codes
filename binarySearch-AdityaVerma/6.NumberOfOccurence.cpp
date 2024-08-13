// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// https://www.youtube.com/watch?v=Ru_HhBFV3Xo&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=6&ab_channel=AdityaVerma

/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int target) {
	    // code here
	    int first=-1;
	    int start=0;
    int end=n-1;
    while(start<=end){
        // int mid=(start+end)/2;                      // might cause overflow due to addition of two large values
        int mid=start + (end-start)/2;                 // prevent overflow
        if(arr[mid]==target){
            first=mid;
            end=mid-1;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    start=0;
    end=n-1;
    int last=-1;
    while(start<=end){
        // int mid=(start+end)/2;                      // might cause overflow due to addition of two large values
        int mid=start + (end-start)/2;                 // prevent overflow
        if(arr[mid]==target){
            last=mid;
            start=mid+1;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(first==-1 && last==-1){
        return 0;
    }
    else{
        return last-first+1;
    }
	}