class Solution:
    def maxLength(self, nums: List[int]) -> int:
        ans = 0
        for i in range (len(nums)):
            g = nums[i]
            l = nums[i]
            p = 1
            for j in range (i, len(nums)):
                g = math.gcd(g, nums[j])
                l = math.lcm(l, nums[j])
                p = p * nums[j]
                if(g * l == p):
                    ans = max(ans, j - i + 1)

        return ans