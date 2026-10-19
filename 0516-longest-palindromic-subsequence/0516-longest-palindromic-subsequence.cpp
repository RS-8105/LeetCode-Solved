class Solution {
public:
    int func(int i, int j, string& s, vector<vector<int>>& dp){
        if(i == s.size() || j == -1)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = 1 + func(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = max(func(i+1, j, s, dp), func(i, j-1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return func(0, s.size() - 1, s, dp);
    }
};