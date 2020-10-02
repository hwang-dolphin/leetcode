
from typing import List

"""
	Notes: use of a pynthon's version of map<int, vector<int>>
"""

class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        myDict = {}
        word1List = []
        word2List = []
        
        minimumValue = 4294967296
        
        for i in range(0, len(words)):
   		    myDict.setdefault(words[i], []).append(i) 
   
        word1List = myDict[word1]
        word2List = myDict[word2]
        
        for i in range(0, len(word1List)):
            for j in range(0, len(word2List)):
                if (abs(word1List[i] - word2List[j]) < minimumValue):
                    minimumValue = abs(word1List[i] - word2List[j])
        
        return minimumValue


words = ["practice", "makes", "perfect", "coding", "makes"]
word1 = "coding"
word2 = "makes"

myObj = Solution()
answer = myObj.shortestDistance(words, word1, word2)

print(answer)
