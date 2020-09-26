
// 时间复杂度 O(n^3) 空间复杂度 O(1)
// 还是使用夹逼法，不多赘述
// 需要注意的是，这里如果 add 一个新的数组，不能直接跳过，因为还可能有另外的组合
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ret = new ArrayList<>();
        if (nums.length < 4)
            return ret;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.length - 2; j++) {
                int b = nums[j];
                if (j > i + 1 && b == nums[j - 1])
                    continue;
                int middle = j + 1;
                int end = nums.length - 1;
                while (middle < end) {
                    int c = nums[middle];
                    int d = nums[end];
                    int ans = target - a - b - c - d;
                    if (ans == 0) {
                        ret.add(Arrays.asList(a, b, c, d));
                        while (nums[middle] == nums[++middle] && middle < end)
                            ;
                    } else if (ans > 0) {
                        middle++;
                    } else
                        end--;
                }
            }
        }
        return ret;
    }
}

/**
 * O(n^3) 的时间复杂度太高，我们用 hashmap 来存储两个数的和，然后再回到 2sum 具体做法是，用另一个 hashmap
 * 存储两个数的值，然后再循环 [i+1,n]，看是否有两个数和的值 match 这里需要比较强的技巧性，首先要对 k 进行循环，也就是找 match
 * 的部分，然后再去构建新的 hashmap（为了下一轮的迭代） 是因为我们 match 的部分必须在 数组[i,j] 之后，不然会出现重复 时间复杂度
 * O(n^2)，空间复杂度 O(n^2)
 */
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length <= 3)
            return result;

        int n = nums.length;
        Arrays.sort(nums);
        Map<Integer, HashSet<List>> map = new HashMap<>();
        Set<String> cache = new HashSet<>();
        for (int i = 0; i < n; i++) {
            // Check if [i + 1, end] can be added up to target
            for (int k = i + 1; k < n; k++) {
                int sum = nums[i] + nums[k];
                if (map.containsKey(target - sum)) {// Try to match up the 4 pairs
                    for (List<Integer> frontPair : map.get(target - sum)) {
                        List<Integer> list = Arrays.asList(frontPair.get(0), frontPair.get(1), nums[i], nums[k]);
                        String key = buildKey(list);
                        if (!cache.contains(key)) {
                            result.add(list);
                            cache.add(key);
                        }
                    }
                }
            }

            // Build up the pair from [0 ~ i]
            for (int j = 0; j < i; j++) {
                int sum = nums[j] + nums[i];
                map.putIfAbsent(sum, new HashSet<>());
                map.get(sum).add(Arrays.asList(nums[j], nums[i]));
            }
        }
        return result;
    }

    private String buildKey(List<Integer> list) {
        StringBuffer sb = new StringBuffer();
        for (int num : list)
            sb.append(num + "@");
        return sb.toString();
    }
}



// K Sum
// 递归的思想，当 k = 2 的时候使用夹逼法计算
// 时间复杂度 O(n^k-1) 空间复杂度 O(1)
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ret = new ArrayList<>();
        Arrays.sort(nums);
        if (nums.length < 4)
            return ret;
        return kSum(nums, 0, 4, target);
    }

    private List<List<Integer>> kSum(int[] nums, int start, int k, int target) {
        List<List<Integer>> ret = new ArrayList<>();
        if (k == 2) {
            int left = start;
            int right = nums.length - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(nums[left]);
                    tmp.add(nums[right]);
                    ret.add(tmp);
                    while (left < right && nums[left] == nums[++left])
                        ;
                } else if (sum > target)
                    right--;
                else
                    left++;
            }
        } else {
            int begin = start;
            int end = nums.length - k + 1;
            while (begin < end) {
                List<List<Integer>> tmp = kSum(nums, begin + 1, k - 1, target - nums[begin]);
                for (List<Integer> t : tmp) {
                    t.add(nums[begin]);
                }
                ret.addAll(tmp);
                while (begin < nums.length - k + 1 && nums[begin] == nums[++begin])
                    ;

            }
        }
        return ret;
    }

}