class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int idx = n / 2;
        sort(nums.begin(), nums.end());
        int median = nums[idx];
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt += abs(median - nums[i]);
        }
        return cnt;
    }
};