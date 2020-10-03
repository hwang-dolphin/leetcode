from typing import List

"""
	Intuition:  traverse through the array and remove the value from array 
			    based on index i
				It is very similar to vector's erase but instead of using a for loop
				in Pynthon a while loop is easier to manipulate the i index value

	RunTime: O(N)
	Space Complexity: O(1) 

"""

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:   
        i = 0
        while (i < len(nums)):
            if (nums[i] == val):
                nums.remove(nums[i])
                i = i - 1
            i = i + 1
                
        return len(nums);

nums = [0,1,2,2,3,0,4,2]
val = 2
myObj = Solution()
answer = myObj.removeElement(nums, val)
print(answer)

