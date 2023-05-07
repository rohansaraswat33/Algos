// TC O(N^2)
// SC O(N)

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] and dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}