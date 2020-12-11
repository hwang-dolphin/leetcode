
from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = []
        
        if (len(nums) == 0):
            return result
        
        
        elif (len(nums) == 1):
            result.append(str(nums[0]))
            return result
        
        minimumPtr = 0
        maximumPtr = 0
        
        for i in range(1, len(nums)):
            if (nums[i] - nums[i - 1] == 1):
                maximumPtr = i
                
                if (i == len(nums) - 1):
                    result.append(str(nums[minimumPtr]) + "->" + str(nums[maximumPtr]))
                
            else:
                if (minimumPtr == maximumPtr):
                    result.append(str(nums[minimumPtr]))
                
                elif (minimumPtr != maximumPtr):
                    result.append(str(nums[minimumPtr]) + "->" + str(nums[maximumPtr]))
                
                
                minimumPtr = i
                maximumPtr = i
                
                if (i == len(nums) - 1):
                    result.append(str(nums[minimumPtr]))
          
        return result


nums = [0,1,2,4,5,7]

myObj = Solution()
answer = myObj.summaryRanges(nums)

print(answer)
