class Solution {
public:
    string digitSum(string s, int k) {
        string st = s;
        while(st.size() > k){
            int cnt = 0;
            int sum = 0;
            string newStr ="";
            for(int i = 0; i<st.size(); i++){
                if(cnt != k){
                    sum += (st[i] - '0');
                    cnt++;
                }
                else if(cnt == k){
                    newStr += to_string(sum);
                    sum = st[i] - '0';
                    cnt = 1;
                }
            }
            newStr += to_string(sum);
            st = newStr;
        }
        return st;
    }
};