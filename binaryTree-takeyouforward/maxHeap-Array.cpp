// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    for (int i = 0; i < n / 2; i++)
    {
        int rootValue = arr[i];
        int leftChildValue = arr[2 * i + 1];
        int rightChildValue = arr[2 * i + 2];

        if (rootValue < leftChildValue || rootValue < rightChildValue)
            return false;
    }
    return true;
}