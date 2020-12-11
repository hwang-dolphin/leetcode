
from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        numsTemp = []
        
        for i in range(0, len(nums)):
            numsTemp.append(nums[i])
        
        for i in range(0, len(nums)):
            nums[int((i + k) % len(nums))] = numsTemp[i]
 


nums = [1,2,3,4,5,6,7]
k = 3
myObj = Solution()
myObj.rotate(nums, k)


for i in range(0, len(nums)):
	print(nums[i])
