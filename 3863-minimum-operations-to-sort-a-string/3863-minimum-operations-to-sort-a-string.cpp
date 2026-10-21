class Solution {
public:
    int minOperations(string s) {
        if (s.size() == 1)
            return 0;
        string st = s;
        sort(st.begin(), st.end());
        if (s == st)
            return 0;
        if (s.size() == 2 && s != st)
            return -1;
        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());
        int n = s.size();
        if(mini == s[0] || maxi == s[n- 1]) return 1;
        for(int i = 1; i<n-1; i++){
            if(mini == s[i] || maxi ==s[i])return 2;
        }
        return 3;
    }
};