

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        ret = []
        if len(nums) < 4:
            return ret
        for i in range(0, len(nums)-3):
            a = nums[i]
            if i > 0 and a == nums[i-1]:
                continue
            for j in range(i+1, len(nums)-2):
                b = nums[j]
                if j > i + 1 and b == nums[j-1]:
                    continue
                middle = j + 1
                end = len(nums) - 1
                while middle < end:
                    c = nums[middle]
                    d = nums[end]
                    ans = target - a - b - c - d
                    if ans == 0:
                        ret.append([a, b, c, d])
                        middle += 1
                        while middle < end and nums[middle] == c:
                            middle += 1
                    elif ans > 0:
                        middle += 1
                    else:
                        end -= 1
        return ret



# kSum
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4: 
            return []
        nums.sort()
        return self.kSum(nums,0,4,target)
    
    def kSum(self,nums,start,k,target):
        ret = []
        if k == 2:
            end = len(nums) - 1
            while start < end:
                ans = nums[start] + nums[end]
                if ans == target:
                    ret.append([nums[start], nums[end]])
                    start += 1
                    while start < end and nums[start] == nums[start - 1]:
                        start += 1
                elif ans > target:
                    end -= 1
                else:
                    start += 1
        else:
            end = len(nums) - k + 1
            while start < end:
                ans = self.kSum(nums,start+1,k-1,target-nums[start])
                for x in ans:
                    x.append(nums[start])
                ret.extend(ans)
                start += 1
                while start < end and nums[start] == nums[start-1]:
                    start+=1
        return ret
                    
                                
        