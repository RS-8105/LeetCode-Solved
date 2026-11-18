class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        int onecnt = 0;
        int zerocnt = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] - '0' == 1){
                onecnt++;
                if(zerocnt%2 != 0){
                    cnt++;
                    onecnt--;
                }
                zerocnt = 0;
            }
            else {
                zerocnt++;
                if(onecnt%2 != 0){
                    cnt++;
                    zerocnt--;
                }
                onecnt = 0;
            }
        }
        return cnt;
    }
};