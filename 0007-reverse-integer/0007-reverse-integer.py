class Solution:
    def reverse(self, x: int) -> int:
        s = str(abs(x))
        rev = s[::-1]
        ans = int(rev)
        if(x < 0):
               ans *= -1
        if(ans < -2**31 or ans >= 2**31):
                return 0
        return ans