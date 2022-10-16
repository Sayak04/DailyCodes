class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        vector<int> helper;
        for(int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int numBack = stoll(s);
            helper.push_back(numBack);
        }
        set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            st.insert(helper[i]);
        }
        return st.size();
    }
};