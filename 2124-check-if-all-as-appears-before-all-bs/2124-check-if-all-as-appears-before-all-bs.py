class Solution:
    def checkString(self, s: str) -> bool:
        b_present = False
        for c in s:
            if(c is 'b'):
                b_present = True
            elif(c is 'a'):
                if(b_present is True):
                    return False
        return True