

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums) 
        descend = 0
        for i in range(n-1,0,-1):
            if nums[i] > nums[i-1]:
                descend = i
                break
        if descend == 0:
            nums.sort()
        else:
            for i in range(n-1,descend - 1,-1):
                if nums[i] > nums[descend - 1]:
                    nums[descend-1],nums[i] = nums[i],nums[descend-1]
                    break
            nums[descend:] = sorted(nums[descend:])