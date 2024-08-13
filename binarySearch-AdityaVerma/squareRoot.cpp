// https://www.youtube.com/watch?v=Bsv3FPUX_BA
// https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

long long int floorSqrt(long long int x)
{
    // Edge cases: if x is 0 or 1, return x
    if (x == 0 || x == 1)
    {
        return x;
    }

    long long int left = 1, right = x, result = 0;

    // Binary search for floor(sqrt(x))
    while (left <= right)
    {
        long long int mid = left + (right - left) / 2;

        // Check if mid*mid is exactly equal to x
        if (mid * mid == x)
        {
            return mid;
        }

        // If mid*mid is less than x, discard the left half
        if (mid * mid < x)
        {
            left = mid + 1;
            result = mid; // mid is a potential answer
        }
        else
        {
            // If mid*mid is greater than x, discard the right half
            right = mid - 1;
        }
    }

    return result;
}