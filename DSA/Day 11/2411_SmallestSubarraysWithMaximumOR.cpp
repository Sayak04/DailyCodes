class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int maxOr = 0;
        for(int i = 0; i < nums.size(); i++) maxOr |= nums[i];
        vector<int> ans;
        int start = 0, end = 1;
        bool reachedEnd = false;
        int partOr = nums[start];
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0) partOr ^= nums[i-1];
            start = i;
            if(reachedEnd) {
                ans.push_back(end - start + 1);
                continue;
            }
            while(end < nums.size() && partOr != maxOr) {
                partOr |= nums[end];
                end++;
            }
            if(end == nums.size()) {
                reachedEnd = true;
            }
            ans.push_back(end - start);
        }
        return ans;
    }
};