
from typing import List

class Solution:
    def countElements(self, arr: List[int]) -> int:
        counter = 0
        
        for i in range(0, len(arr)):
            if (arr[i] + 1 in arr):
                counter = counter + 1
        
        return counter



arr = [1,3,2,3,5,0]
myObj = Solution()
answer = myObj.countElements(arr)
print(answer)
