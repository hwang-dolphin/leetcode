class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        myMap = {}      #empty dictionary
        output = []     #empty vector

        for i in range(0, len(nums)):
            if nums[i] not in myMap:
                myMap[nums[i]] = 1
            elif nums[i] in myMap:
                myMap[nums[i]] = myMap[nums[i]] + 1
            #print(myMap[nums[i]])
            if (myMap[nums[i]] > (len(nums) / 3)):
                if (nums[i] not in output):
                    output.append(nums[i])
        
        return output
    
