class Solution {
public:
    int func(int i , int buy, int times, vector<int> & prices, vector<vector<vector<int>>>& dp){
        if(i == prices.size())return 0;
        if(dp[i][buy][times] != -1)return dp[i][buy][times];
        int pick = INT_MIN;
        if(buy == 0){
            if(times < 2){
                pick = prices[i] + func(i + 1, 1, times + 1, prices, dp);
            }
        }
        else {
            pick = -prices[i] + func(i + 1, 0, times, prices, dp);
        }

        int notPick = func(i+1, buy, times, prices, dp);

        return dp[i][buy][times] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>> (2, vector<int>(3 , -1)));
        return func(0, 1, 0, prices, dp);
    }
};