from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        myMap = {}
        mySet = set()
        for i in range(0, len(arr)):
            if (arr[i] in myMap):
                myMap[arr[i]] = myMap[arr[i]] + 1
            else:
                myMap[arr[i]] = 1
        
        for key in myMap:
            mySet.add(myMap[key])
        
        if (len(mySet) == len(myMap)):
            return 1
        else:
            return 0


arr = [1,2,2,1,1,3]
myObj = Solution()
answer = myObj.uniqueOccurrences(arr)	

print(answer)
