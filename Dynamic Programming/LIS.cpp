// #Recursion
class Solution
{
    int f(int i, int prev, int n, vector<int> &nums)
    {
        if (i == n)
        {
            return 0;
        }
        int notTake = f(i + 1, prev, n, nums);
        int take = 0;
        if (prev == -1 or nums[i] > nums[prev])
        {
            take = 1 + f(i + 1, i, n, nums);
        }
        return max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return f(0, -1, n, nums);
    }
};
// #Memoization

class Solution
{
    int f(int i, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }

        int notTake = f(i + 1, prev, n, nums, dp);
        int take = 0;
        if (prev == -1 or nums[i] > nums[prev])
        {
            take = 1 + f(i + 1, i, n, nums, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(0, -1, n, nums, dp);
    }
};

// #Tabulation

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int notTake = dp[i + 1][prev + 1];
                int take = 0;
                if (prev == -1 or nums[i] > nums[prev])
                {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// #Space Optimization
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> next(n + 1, 0);
        vector<int> curr = next;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int notTake = next[prev + 1];
                int take = 0;
                if (prev == -1 or nums[i] > nums[prev])
                {
                    take = 1 + next[i + 1];
                }
                curr[prev + 1] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
};

// #Most Important Method
// **this method is also used to print LIS **

class Solution
{
public:
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
};

// #To Print LIS

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++)
            hash[i] = i;
        int len = 0;
        int lastLISind = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] and dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            len = max(len, dp[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == len)
            {
                lastLISind = i;
            }
        }
        int ind = lastLISind;
        vector<int> LIS;
        LIS.push_back(nums[ind]);
        while (hash[ind] != ind)
        {
            ind = hash[ind];
            LIS.push_back(nums[ind]);
        }
        reverse(LIS.begin(), LIS.end());
        for (auto it : LIS)
        {
            cout << it << " ";
        }
        cout << endl;
        return len;
    }

    // #Using Binary Search
    class Solution
    {
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> temp;
            temp.push_back(nums[0]);
            for (int i = 1; i < n; i++)
            {
                if (nums[i] > temp.back())
                {
                    temp.push_back(nums[i]);
                }
                else
                {
                    int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                    temp[ind] = nums[i];
                }
            }
            return temp.size();
        }
    };