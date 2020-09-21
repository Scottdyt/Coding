

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ret = sum(nums[:3])
        for begin in range(0,len(nums)-2):
            a = nums[begin]
            if begin > 0 and nums[begin] == nums[begin-1]:
                continue
            middle = begin + 1
            end = len(nums) -1
            while middle < end:
                b = nums[middle]
                c = nums[end]
                ans = target - a - b - c
                if abs(ans) < abs(target - ret):
                    ret = a + b + c
                if ans > 0:
                    middle += 1
                elif ans == 0:
                    return target
                else:
                    end -= 1
        return ret
                
        