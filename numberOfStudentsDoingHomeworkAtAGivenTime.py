
from typing import List

class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        
        counter = 0;
 
        for i in range(0, len(startTime)):
            if (queryTime >= startTime[i] and queryTime <= endTime[i]):
                counter = counter + 1
              
        return counter



startTime = [9,8,7,6,5,4,3,2,1]
endTime = [10,10,10,10,10,10,10,10,10]
queryTime = 5
myObj = Solution()
answer = myObj.busyStudent(startTime, endTime, queryTime)
print(answer)
