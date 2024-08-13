// https://www.interviewbit.com/problems/container-with-most-water/
// https://leetcode.com/problems/container-with-most-water/description/
// https://leetcode.com/problems/container-with-most-water/solutions/3701708/best-method-c-java-python-beginner-friendly

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right)
        {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};