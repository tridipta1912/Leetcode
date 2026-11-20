class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        last = [0] * 26
        for i in range(len(s)):
            last[ord(s[i]) - 97] = i
        ans = [0]
        maxx = 0
        for i in range(len(s)):
            maxx = max(maxx, last[ord(s[i]) - 97])
            ans[-1] += 1
            if(maxx == i):
                ans.append(0)
        if(ans[-1] == 0):
            ans.pop()
        return ans