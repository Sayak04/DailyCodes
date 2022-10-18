class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        string ans = "11";
        for(int i = 3; i <= n; i++) {
            char dig = ans[0], cnt = 1;
            string newAns = "";
            for(int j = 1; j < ans.length(); j++) {
                if(dig != ans[j]) {
                    newAns += to_string(cnt);
                    newAns += dig;
                    dig = ans[j];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            if(cnt > 0) {
                newAns += to_string(cnt);
                newAns += dig;
            }
            ans = newAns;
        }
        return ans;
    }
};