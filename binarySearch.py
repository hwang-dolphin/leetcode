from typing import List

"""
	Intuition:  Simple binary search of a ordered array.
	RunTime: O(Log N)
	Space Complexity: O(1)
"""

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        result = -1
        
        while (left <= right):
            middle = int((right - left) / 2) + left;
            
            if (nums[middle] == target):
                result = middle
                break
            
            elif (target > nums[middle]):
                left = middle + 1
            
            elif (target < nums[middle]):
                right = middle - 1;
            
        return result


myList = [-1,0,3,5,9,12]
target = 9

myObj = Solution()

answer = myObj.search(myList, target)

print(answer)
