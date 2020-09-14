// https://leetcode.com/problems/container-with-most-water/

// naive approach
// O(n^2) expensive!
class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int maxn = -1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int result = (j - i) * Math.min(height[i], height[j]);
                if (result > maxn) {
                    maxn = result;
                }
            }
        }
        return maxn;
    }
}

/**
 * O(n) time complex O(1) space complexity 
 * 用类似贪心发的思想，根据木桶原理，每次将 start / end
 * 指针中较矮的那一个往后移一位，更新 result 这样保证一定是往着面积更大的方向搜索 假设最佳面积 v1 的位置是[x1,x2]，若算法指向的最大的面积
 * v2 的位置是[x3,x4] 若 [x3,x4] 在 [x1,x2] 内或者外，则一定会被探索到 因此假设 x3 < x1, x4 < x2, 大小关系为
 * x3,x1,x4,x2； 那么当指针指向 x4 之前，一定指向过 x2，则 [x3,x2] 的面积被探索过； 此时算法讲 x2 往前移动，说明 x3
 * 的高度大于 x2，则 [x3,x2] 的面积为 (x2 - x3) * h(x2)； 而 [x1,x2] 的体积为 (x2- x1) *
 * min(h(x1),h(x2))，一定小于 [x3,x2] 的面积； 因此 [x3,x2] 不是最大值，反证成立
 */

class Solution {
    public int maxArea(int[] height) {
        int maxn = -1;
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int result = (end - start) * Math.min(height[end], height[start]);
            maxn = Math.max(maxn, result);
            if (height[start] > height[end]) {
                end--;
            } else {
                start++;
            }
        }
        return maxn;

    }
}
