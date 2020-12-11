from typing import List

"""
	Intuition: Simple sliding window of two elements
	RunTime: O(N), N = size of releaseTimes
	Space Complexity: O(1)
"""



class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        result = keysPressed[0]
        longest = releaseTimes[0]
        
        for i in range(1, len(releaseTimes)):
            if ((releaseTimes[i] - releaseTimes[i - 1]) > longest):
                longest = releaseTimes[i] - releaseTimes[i - 1]
                result = keysPressed[i]
        
            elif ((releaseTimes[i] - releaseTimes[i - 1]) == longest):
                if (result <= keysPressed[i]):
                    result = keysPressed[i]
        
        return result


releaseTimes = [9,29,49,50]
keysPressed = "cbcd"


myObj = Solution()
answer = myObj.slowestKey(releaseTimes,  keysPressed)
print(answer)
