class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        if (cost1 >= costBoth && costBoth <= cost2) {
            return 1LL * costBoth * max(need1, need2);
        } else if (cost1 < costBoth && costBoth > cost2) {
            if (costBoth >= cost1 + cost2)
                return 1LL * cost1 * need1 + 1LL * cost2 * need2;
            int m = min(need1, need2);
            return 1LL * costBoth * m + 1LL * cost1 * (need1 - m) +
                   1LL * cost2 * (need2 - m);
        } else if (costBoth < cost1 && costBoth > cost2) {
            if (need1 < need2) {
                return 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1);
            } else {
                return 1LL * costBoth * need1;
            }
        } else {
            if (need1 > need2) {
                return 1LL * costBoth * need2 + 1LL * cost1 * (need1 - need2);
            } else {
                return 1LL * costBoth * need1 +
                       1LL * min(cost2, costBoth) * (need2 - need1);
            }
        }
        return 0;
    }
};