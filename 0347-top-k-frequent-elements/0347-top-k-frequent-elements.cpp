class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> mpp;
        int cnt = 1;
        for(int i = 0; i<nums.size() - 1; i++){
            if(nums[i] != nums[i+1]){
                mpp.push_back({cnt, nums[i]});
                cnt = 1;
            }
            else cnt++;
        }
        mpp.push_back({cnt, nums[nums.size() - 1]});
        sort(mpp.begin(), mpp.end(), greater<pair<int,int>>());
        for(int i = 0; i<k; i++){
            ans.push_back(mpp[i].second);
        }
        return ans;
    }
};