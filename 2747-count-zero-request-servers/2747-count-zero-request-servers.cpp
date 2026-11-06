class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), cmp);
        vector<pair<int, int>> que;
        for(int i = 0; i<queries.size(); i++){
            que.push_back({queries[i], i});
        }
        sort(que.begin(), que.end());
        vector<int> freq(n+1, 0);
        int distinct = 0;
        int l = 0;
        int r = 0;
        vector<int> ans(queries.size());
        for(auto q: que){
            int low = q.first - x;
            int up = q.first;
            while(r<logs.size() && logs[r][1] <= up){
                freq[logs[r][0]]++;
                if(freq[logs[r][0]] == 1) distinct++;
                r++;
            }
            while(l<logs.size() && logs[l][1] < low){
                freq[logs[l][0]]--;
                if(freq[logs[l][0]] == 0)distinct--;
                l++;
            }
            ans[q.second] = n - distinct;
        }
        return ans;
    }
};