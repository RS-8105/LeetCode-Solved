class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 0;
        int lastIndex = 0;
        vector<int> hash(n), dp(n, 1);
        for (int i = 1; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    hash[i] = prev;
                    dp[i] = dp[prev] + 1;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans;
        int cur = lastIndex;
        while (hash[cur] != cur) {
            ans.push_back(nums[cur]);
            cur = hash[cur];
        }
        ans.push_back(nums[cur]);
        return ans;
    }
};