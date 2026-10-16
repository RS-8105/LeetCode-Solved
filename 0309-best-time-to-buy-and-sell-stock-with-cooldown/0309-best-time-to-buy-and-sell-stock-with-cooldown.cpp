class Solution {
public:
    int func(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int pick;
        if (buy == 1)
            pick = -prices[i] + func(i + 1, 0, prices, dp);
        else
            pick = prices[i] + func(i + 2, 1, prices, dp);
        int notPick = func(i + 1, buy, prices, dp);

        return dp[i][buy] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return func(0, 1, prices, dp);
    }
};