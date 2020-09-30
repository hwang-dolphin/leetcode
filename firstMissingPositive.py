from typing import List



class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        counter = 1
        
        nums.sort()
        
        myUniqueList = []
        
        for i in range(0, len(nums)):
            if (nums[i] not in myUniqueList):
                myUniqueList.append(nums[i])
            
        for i in range(0, len(myUniqueList)):
            if (myUniqueList[i] > 0 and myUniqueList[i] == counter):
                counter = counter + 1
            elif (myUniqueList[i] > 0 and myUniqueList[i] != counter):
                break
        
        return counter
       
nums = [0,1,1,2,2]
myObj = Solution()
answer = myObj.firstMissingPositive(nums)

print(answer)
