// https://www.youtube.com/watch?v=3RhGdmoF_ac&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=16&ab_channel=AdityaVerma
// https://www.callicoder.com/minimum-difference-element-in-sorted-array/#:~:text=Given%20an%20array%20of%20integers,'5'%20is%20the%20minimum.

// Think about approach given below it may help:
// floor : end pointer after the whole execution of loop,if mid is not exist.
// ceil : start pointer after the whole execution of loop,if mid is not exist.

// If you analyze the start and end indices point to the numbers that are closest to the target value being searched for.
// at the end of the loop, the start index points to the ceiling of the target and the end index points to the floor of the target value.
// If we find the target, then we return it as the minimum difference element.
// If we can’t,  then at the end of the loop, we can find the differences between the target and
// the numbers at indices start and end, as these two numbers will be closest to the target.
// The number that gives minimum difference will be the output.

private
static int binarySearchMinDifference(int[] a, int target)
{
    int n = a.length;

    if (target < a[0])
        return a[0];
    if (target > a[n - 1])
        return a[n - 1];

    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (target == a[mid])
        {
            return a[mid];
        }
        else if (target < a[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    /*
       At the end of the while loop,
       a[start] is the ceiling of target (Smallest number greater than target), and
       a[end] is the floor of target (Largest number smaller than target).

       Return the element whose difference with target is smaller
     */
    if ((a[start] - target) < (target - a[end]))
        return a[start];
    return a[end];
}