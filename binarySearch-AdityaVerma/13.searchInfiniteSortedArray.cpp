// https://www.youtube.com/watch?v=FzvK5uuaki8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=13&ab_channel=AdityaVerma

// C++ program to demonstrate working of an algorithm that finds
// an element in an array of infinite size
#include<bits/stdc++.h>
using namespace std;

// Simple binary search algorithm
int binarySearch(int arr[], int l, int r, int x)
{
	if (r>=l)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid-1, x);
		return binarySearch(arr, mid+1, r, x);
	}
	return -1;
}

// function takes an infinite size array and a key to be
// searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(int arr[], int key)
{
	int l = 0, h = 1;
	// int val = arr[0];

	// Find h to do binary search
	while (arr[h] < key)
	{
		l = h;	 // store previous high
		h = 2*h;	 // double high index
		// val = arr[h]; // update new val
	}

	// at this point we have updated low and
	// high indices, Thus use binary search
	// between them
	return binarySearch(arr, l, h, key);
}

// Driver program
int main()
{
	int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
							140, 160, 170};
	int ans = findPos(arr, 10);
	if (ans==-1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans;
	return 0;
}
