class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> v;
        vector<int> powers;
        int x = n;
        while(x > 0) {
            v.push_back(x % 2);
            x = x / 2;
        } 
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
                powers.push_back(pow(2,i));
            }
        }
        vector<int> ans;
        for(auto it: queries) {
            long long pro = 1;
            for(int i = it[0]; i <= it[1]; i++) {
                pro = ((pro % 1000000007) * (powers[i] % 1000000007)) % 1000000007;
            }
            ans.push_back(pro % 1000000007);
        }
        return ans;
    }
};