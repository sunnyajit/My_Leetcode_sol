 class Solution {
    public int[] findErrorNums(int[] nums) {
        int [] ans = new int[2];
// code written by sunny
        for(int val : nums){
            int i = Math.abs(val) - 1;
            if(nums[i] < 0){
                ans[0] = Math.abs(val);
            }else{
                nums[i] = -nums[i];
            }
        }
        for(int i=0; i<nums.length; i++){
            if(nums[i]>0){
                ans[1] = i+1;
            }
        }

        return ans;
    }
}