
# O(n) time complex O(1) space complex
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxn = -1
        begin = 0
        end = len(height) - 1
        while begin < end:
            result = min(height[begin],height[end]) * (end - begin)
            maxn = maxn if maxn > result else result
            if height[begin] > height[end]:
                end -= 1
            else:
                begin += 1
        return maxn
        