from typing import List

class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        myDict = {}
        
        for i in range(0, len(nums)):
            if (nums[i] in myDict):
                myDict[nums[i]] = myDict[nums[i]] + 1
            else:
                myDict[nums[i]] = 1
                
        if (target in myDict and myDict[target] > int(len(nums) / 2)):
            return True
        
        else:
            return False


nums = [2,4,5,5,5,5,5,6,6]
target = 5

myObj = Solution()
answer = myObj.isMajorityElement(nums, target)
print(answer)
