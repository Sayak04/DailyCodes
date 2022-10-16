class Solution {
    public int findMaxK(int[] nums) {
        Arrays.sort(nums);
        int end = nums.length - 1, start = 0;
        while(start < end) {
            if((nums[start] * -1) == nums[end]) {
                return nums[end];
            } 
            else if((nums[start] * -1) < nums[end]) end--;
            else start++;
        }
        return -1;
    }
}