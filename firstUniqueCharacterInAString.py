
"""
	Intuition: use two pass.  In first pass, create a dictionary with the frequencies of
		   characters.  In the second pass, traverse through the string s checking
		   which is the first character that has a frequency of "one".  

	RunTime: O(N)
	Space Complexity: O(N)
"""

class Solution:
    def firstUniqChar(self, s: str) -> int:
        myDict = {}
        result = -1
        for i in range(0, len(s)):
            if (s[i] in myDict):
                myDict[s[i]] = myDict[s[i]] + 1
            else:
                myDict[s[i]] = 1
        
        for i in range(0, len(s)):
            if (myDict[s[i]] == 1):
                result = i
                break
        
        return result


s = "loveleetcode"
myObj = Solution()
answer = myObj.firstUniqChar(s)

print(answer)
