class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.length();
        int m = s.length();
        if(n>s.length()) return "";
        unordered_map<char, int> checker, adjuster;
        for (int i = 0; i < n; i++)
            checker[t[i]]++;
        string ans = "";
        int cnt = 0;
        int minLength = INT_MAX;
        for(int i = 0, j = 0; j < m; j++){
            char c = s[j];
            if(checker.find(c) != checker.end()){
                adjuster[c]++;
                if(adjuster[c] <= checker[c]){
                    cnt++;
                }
            }
            if(cnt>=n){
                while(checker.find(s[i]) == checker.end() || adjuster[s[i]] > checker[s[i]]){
                    adjuster[s[i]]--;
                    i++;
                }
                if(j - i + 1 < minLength){
                    minLength = j - i + 1;
                    ans = s.substr(i, minLength);
                }
            }
        }
        return ans;
    }
};