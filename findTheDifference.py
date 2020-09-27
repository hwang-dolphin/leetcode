class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for i in range(0, len(s)):
            t = t.replace(s[i], '',1)
   
        return t[0];



