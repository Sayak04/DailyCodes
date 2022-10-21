class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        for(auto it: mpp) {
            for(int i = 1; i < it.second.size(); i++) {
                if(abs(it.second[i] - it.second[i-1]) <= k) return true;
            }
        }
        return false;
    }
};