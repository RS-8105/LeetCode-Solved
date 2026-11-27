class Solution {
public:
    int func(int i, int budget, bool purchased, vector<vector<int>>& items,
             vector<int>& freeitems, vector<vector<array<int, 2>>>& dp) {
        if (i == items.size() || budget == 0)
            return 0;
        if (dp[i][budget][purchased] != -1)
            return dp[i][budget][purchased];
        int pick = 0;

        if (items[i][1] <= budget) {

            if (!purchased)
                pick =
                    1 + freeitems[i] +
                    func(i, budget - items[i][1], true, items, freeitems, dp);
            else
                pick = 1 + func(i, budget - items[i][1], true, items, freeitems,
                                dp);
        }

        int notPick = func(i + 1, budget, false, items, freeitems, dp);

        return dp[i][budget][purchased] = max(pick, notPick);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freeitems(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeitems[i]++;
                }
            }
        }
        vector<vector<array<int, 2>>> dp(
            n, vector<array<int, 2>>(budget + 1, {-1, -1}));
        return func(0, budget, false, items, freeitems, dp);
    }
};