class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;

        for(int i = 0; i < n; i++) {
            int gcdd = nums[i];
            long long prod = nums[i];
            long long lcmm = nums[i];

            for(int j = i + 1; j < n; j++) {
                gcdd = gcd(gcdd, nums[j]);
                lcmm = lcm(lcmm, (long long)nums[j]);
                prod *= nums[j];

                if(prod > 25200)
                    break;

                if(prod == gcdd * lcmm) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};