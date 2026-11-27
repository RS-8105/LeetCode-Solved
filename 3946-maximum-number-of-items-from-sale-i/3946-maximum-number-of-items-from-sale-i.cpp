class Solution {
public:
    int func(int i, int budget, int minPrice,
             vector<vector<int>>& items,
             vector<int>& freeitems,
             vector<vector<int>>& dp) {

        if (i == items.size())
            return budget / minPrice;

        if (dp[i][budget] != -1)
            return dp[i][budget];

        int pick = 0;

        if (items[i][1] <= budget) {
            pick = 1 + freeitems[i] +
                   func(i + 1, budget - items[i][1],
                        minPrice, items, freeitems, dp);
        }

        int notPick = func(i + 1, budget, minPrice,
                           items, freeitems, dp);

        return dp[i][budget] = max(pick, notPick);
    }

    int maximumSaleItems(vector<vector<int>>& items,
                         int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freeitems(n, 0);

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j &&
                    items[j][0] % items[i][0] == 0) {
                    freeitems[i]++;
                }
            }
        }

        vector<vector<int>> dp(
            n, vector<int>(budget + 1, -1)
        );

        return func(0, budget, minPrice,
                    items, freeitems, dp);
    }
};