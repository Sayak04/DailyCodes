class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        if(n == 1) return; 
        int low = -1, high = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                low = i;
                break; 
            }
        }            
        for(int i = low + 1; i < n; i++) {
            if(nums[i] != 0) {
                high = i;
                break;
            }
        }
        if(low == -1 || high == -1) return;
        while(high < n) {
            if(nums[low] == 0 && nums[high] != 0) {
                swap(nums[high], nums[low]);
                high++;
                low++;
            } else if(nums[high] == 0) nums[high]++; 
        }
    }
}