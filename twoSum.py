from typing import List

"""
	Intuition: Simple brute force
	RunTime: O(N^2)
	Space Complexity: O(1)
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer = []

        found = False
        for i in range(0, len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if (nums[i] + nums[j] == target):
                    answer.append(i)
                    answer.append(j)
                    found = True
                    break
            
            if (found == True):
                break
        
        return answer



nums = [3,2,4]
target = 6

myObj = Solution()
result = []
result = myObj.twoSum(nums, target)

for i in range(0, len(result)):
	print(result[i])
