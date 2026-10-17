class Solution {
public:
    int func(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1)return dp[i][prev];
        int pick = INT_MIN;
        if(prev == 0 || nums[prev - 1] < nums[i])
        pick = 1 + func(i+1, i+1, nums, dp);

        int notPick = 0 + func(i + 1, prev, nums, dp);

        return dp[i][prev] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n +1, vector<int> (n + 1, -1));
        return func(0, 0, nums, dp);   
    }
};