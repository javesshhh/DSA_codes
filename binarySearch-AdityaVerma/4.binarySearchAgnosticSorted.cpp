// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function.
int binarySearch(int arr[], int start, int end, int x)
{

	// Checking the sorted order of the given array
	bool isAsc = arr[start] < arr[end];
	while (start <= end) {
		int middle = start + (end - start) / 2;

		// Check if x is present at mid
		if (arr[middle] == x)
			return middle;

		// Ascending order
		if (isAsc == true) {

			// If x greater, ignore left half
			if (arr[middle] < x)
				start = middle + 1;

			// If x smaller, ignore right half
			else
				end = middle - 1;
		}

		// Descending order
		else {

			// If x smaller, ignore left half
			if (arr[middle] > x)
				start = middle + 1;

			// If x greater, ignore right half
			else
				end = middle - 1;
		}
	}

	// Element is not present
	return -1;
}

// Driver Code
int main()
{
	int arr[] = { 40, 10, 5, 2, 1 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << binarySearch(arr, 0, n - 1, x);

	return 0;
}
