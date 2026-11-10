class Solution {
public:
    int func(int i, vector<int>& costs, vector<int>& dp) {
        if (i == costs.size())
            return 0;
        if(dp[i] != -1)return dp[i];
        int n = costs.size();
        int i1 = INT_MAX, i2 = INT_MAX, i3 = INT_MAX;
        if (i + 1 <= n)
            i1 = 1 + costs[i] + func(i + 1, costs, dp);
        if (i + 2 <= n)
            i2 = 4 + costs[i + 1] + func(i + 2, costs, dp);
        if (i + 3 <= n)
            i3 = 9 + costs[i + 2] + func(i + 3, costs, dp);

        return dp[i] = min(i1, min(i2, i3));
    }
    int climbStairs(int n, vector<int>& costs) { 
        vector<int> dp(n, -1);
        return func(0, costs, dp); 
    }
};