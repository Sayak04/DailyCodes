class Solution {
    public int minimizeArrayValue(int[] nums) {
        long maxi = nums[0];
        long sum = nums[0];
        for(int i = 1; i < nums.length; i++) {
            sum += nums[i];
            long avg = (sum + i) / (i+1);
            maxi = Math.max(maxi, avg); 
        }
        return (int)maxi;
    }
}