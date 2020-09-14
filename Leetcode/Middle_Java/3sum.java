
// navie approach 
// Time Limit Exceeded O(n^3) time complex!!!
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        int n = nums.length;
        Arrays.sort(nums);
        if (n < 3)
            return ret;
        for (int i = 0;i < n-2; i++){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int a = nums[i];
            for (int j = i+1; j < n -1; j++){
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int b = nums[j];
                for (int k = j + 1; k < n; k++){
                    if (k  > j + 1 && nums[k] == nums[k-1])
                        continue;
                    int c = nums[k];
                    if (a + b + c == 0)
                        ret.add(Arrays.asList(a,b,c));
                }
            }
        }
        return ret;
    }
}




/**
 * Wrong answer
 * [-4,-1,-1,0,2] cannot get result
 * 想法：控制左右两边的，对中间对那个数 b 进行遍历，然后逐渐缩小边界
 * 错误：缩小边界的时候无法得到所有的组合数
 */


// class Solution {
//     public List<List<Integer>> threeSum(int[] nums) {
//         List<List<Integer>> ret = new ArrayList<List<Integer>>();
//         int n = nums.length;
//         Arrays.sort(nums);
//         if (n < 3)
//             return ret;
//         int begin = 0;
//         int end = n -1;
//         while (begin < end - 1){
//             int middle = begin + 1;
//             int a = nums[begin];
//             int c = nums[end];
//             while (middle < end){
//                 int b = nums[middle];
//                 if (a + b + c == 0){
//                     ret.add(Arrays.asList(a,b,c));
//                     break;
//                 }
//                 else
//                     middle++;
//             }
//             begin++;
//             end--;
//             while (nums[begin] == a && begin < end -1)
//                 begin++;
//             while(nums[end] == c && begin < end -1)
//                 end--;
//         }
//         return ret;
//     }
// }


/**
 * 时间复杂度 O(n^2)
 * 注意，要考虑重复问题，特别是当三个数等于 0 的时候的指针移动
 * 首先确定一个数，然后使用夹逼法
 */

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        int n = nums.length;
        Arrays.sort(nums);
        if (n < 3)
            return ret;
        for (int begin = 0; begin < n -2; begin++){
            if (begin > 0 && nums[begin] == nums[begin-1])
                continue;
            int a = nums[begin];
            int middle = begin + 1;
            int end = n - 1;
            while (middle < end){
                int b = nums[middle];
                int c = nums[end];
                if (a + b + c == 0){
                    ret.add(Arrays.asList(a,b,c));
                    while (middle < end && nums[middle] == nums[++middle]); // important!
                }
                else if (a + b + c < 0){
                    middle++;
                }
                else
                    end--;
            }
        }
        return ret;
    }
}