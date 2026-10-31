class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans = ""
        n = len(strs)
        cur = 0
        while(1):
            for s in strs:
                if(len(s) <= cur or s[cur] != strs[0][cur]):
                    return ans
            ans += strs[0][cur]
            cur += 1
        return ans
            