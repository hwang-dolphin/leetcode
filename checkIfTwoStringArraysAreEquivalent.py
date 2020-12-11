from typing import List

class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
    
        wordResult1List = []
        wordResult2List = []
        
        for i in range(0, len(word1)):
           wordResult1List.insert(len(wordResult1List),word1[i])
        
        for i in range(0, len(word2)):
            wordResult2List.insert(len(wordResult2List),word2[i])
        
        wordResult1 = "".join(wordResult1List)
        wordResult2 = "".join(wordResult2List)
        
        if (wordResult1 == wordResult2):
            result = 1
        
        else:
            result = 0
    
        return result

word1 = ["a", "cb"]
word2 = ["ab", "c"]

myObj = Solution()

answer = myObj.arrayStringsAreEqual(word1, word2)

print(answer)



