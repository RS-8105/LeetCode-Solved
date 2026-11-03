class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        long long sum = 0;
        for(int x : nums){
            sum += x;
        }
        long long moves = sum - (long long)nums.size() * mini;
        return (int)moves;
    }
};