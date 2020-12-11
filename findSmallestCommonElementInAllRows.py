from typing import List


"""
	Intuition:  Take advantage of the fact that the arrays in mat do not have duplicates.
				This way we can create a dictionary of number frequencies.  We should search
				in the dictionary of frequencies for the smallest key which have a frequency
				equal to the size of "mat" array.

	RunTime: O(NM), N = number of elements in mat, M = number of elements in N
	Space Complexity: O(K), K = number of unique elements
"""



class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        result = -1
        
        myDict = {}
        
        for i in mat:
            for j in i:
                if (j not in myDict):
                    myDict[j] = 1
                else:
                    myDict[j] = myDict[j] + 1

        for key, value in myDict.items():
            if (value == len(mat)):
                result = key
                break
            
        return result



mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
myObj = Solution()
answer = myObj.smallestCommonElement(mat)

print(answer)
