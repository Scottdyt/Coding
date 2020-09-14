
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        if len(nums) < 3:
            return ret
        nums.sort()
        for begin in range(len(nums)-2):
            if begin > 0 and nums[begin] == nums[begin - 1]:
                continue
            a = nums[begin]
            middle = begin + 1
            end = len(nums) - 1
            while middle < end:
                b = nums[middle]
                c = nums[end]
                if a + b + c == 0:
                    ret.append([a,b,c])
                    middle += 1
                    while middle < end and nums[middle] == nums[middle - 1]:
                        middle += 1
                elif a + b + c < 0:
                    middle += 1
                else:
                    end -= 1
        return ret
        
        
        