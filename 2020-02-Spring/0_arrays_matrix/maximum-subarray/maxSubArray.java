class maxSubArray {
    public int maxSubArray(int[] nums) {
    if (nums.length == 1) {
        return nums[0];
    }
    //Keep track of the max sum seen so far, and the current running sum.
    int max = nums[0];
    int curr = 0;
    for (int i = 0; i < nums.length; i++) {
        curr += nums[i];
        //If the current running sum is greater than the total, set it to max.
        if (curr > max) {
            max = curr;
        }
        //If the current running total becomes negative, we ignore the numbers
        if (curr < 0) {
            curr = 0;
        }
    }
    return max;
}
}