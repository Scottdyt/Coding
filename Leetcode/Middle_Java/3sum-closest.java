
// 时间复杂度 O(n^2) 空间复杂度 O(1)
// 与 3sum 一样的夹逼法，注意如果为当前的 target，直接返回
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ret = nums[0] + nums[1] + nums[2];
        for (int begin = 0; begin < nums.length -2; begin++){
            if (begin > 0 && nums[begin] == nums[begin-1]){
                continue;
            }
            int a = nums[begin];
            int middle = begin + 1;
            int end = nums.length - 1;
            while (middle < end){
                int b = nums[middle];
                int c= nums[end];
                int ans = target - a - b - c;
                if (Math.abs(ans) < Math.abs(ret - target)){
                    ret = a + b + c;
                }
                if (ans == 0){
                    return target;   
                }
                else if (ans > 0){
                    middle ++;
                }
                else
                    end --;    
            }
        }
        return ret;
    }
}