class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;
        int minSum = INT_MAX, msum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }

        for (int i = 0; i < n; i++)
        {
            msum += nums[i];
            minSum = min(minSum, msum);
            if (msum > 0) msum = 0;
        }

        return max(abs(maxSum), abs(minSum));
    }
};
