class Solution:
    def toLowerCase(self, str: str) -> str:
        newStr = ""
        for i in range(0, len(str)):
            if (str[i].isupper()):
                newStr += str[i].lower()
            else:
                newStr += str[i]
        return newStr


givenStr = "Goog Morning!"

myObj = Solution()
print(myObj.toLowerCase(givenStr))
