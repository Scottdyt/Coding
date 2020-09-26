

/**
 * https://leetcode.com/problems/next-permutation/solution/
 * 从右左看，找到第一个 a[i] > a[i-1] 的数，也就是，右边的序列已经是最大了
 * 然后将 a[i] 与右边的序列中，大于他的最小的数进行调换
 * 注意，这里由于右边一定是单调递增序列，只需要从右往左遍历即可
 * 调换完成后，再将 a[i-1] 右边的序列从小到大排列，得到以 a[i] 为首的，最小字典序
 * */ 

class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int ascend = 0;
        for (int i = n -1; i >= 1; i--){
            if (nums[i] > nums[i-1]){
                ascend = i;
                break;
            }
        }
        if (ascend == 0){
            Arrays.sort(nums);
        }
        else{
            int a = ascend - 1;
            int b = ascend;
            for (int i = n-1; i >= ascend; i--){
                if (nums[i] > nums[a]){
                    b = i;
                    break;
                }
            }
            swap(nums,a,b);
            Arrays.sort(nums,ascend,n);
        }
    }
    
    
    private void swap(int[] nums,int a,int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
    
}