class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        counter = 0;
        
        if (len(word) == 1):
            return 1
        
        for i in range(0, len(word)):
            if (word[i].isupper()):
                counter = counter + 1
        
        if (counter == 0 or counter == len(word)):
            return 1
        elif (counter == 1 and word[0].isupper()):
            return 1
        else:
            return 0


myObj = Solution()
print(myObj.detectCapitalUse("Facebook"))
