class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        a = []
        n = len(nums)
        for i in range(n):
            for j in range(n):
                if(i != j and nums[i] + nums[j] == target):
                    a.append(i)
                    a.append(j)
                    return a
        pass