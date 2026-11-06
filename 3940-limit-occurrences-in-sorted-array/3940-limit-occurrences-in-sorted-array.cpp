class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int freq = 1;
        ans.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            if(freq<k){
                ans.push_back(nums[i]);
                if(nums[i] == nums[i-1])
                    freq++;
                else 
                    freq = 1;
            }
            else {
                if(nums[i] == nums[i-1]){
                    continue;
                }
                else{
                    ans.push_back(nums[i]);
                    freq = 1;
                }
            }
        }
        return ans;
    }
};