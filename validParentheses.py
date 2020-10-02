class Solution:
    def isValid(self, s: str) -> bool:
        myStack = []
        closingChars = ")}]"
        result = True
        
        if (int(len(s) % 2) != 0):
            return False
        
        for i in range(0, len(s)):
            if (s[i] not in closingChars):
                myStack.append(s[i])
            
            elif (s[i] in closingChars and len(myStack) == 0):
                result = False
                return result
            
            elif ((myStack[len(myStack) - 1] == '(' and s[i] == ')') or
                  (myStack[len(myStack) - 1] == '{' and s[i] == '}') or
                  (myStack[len(myStack) - 1] == '[' and s[i] == ']')):
            
                myStack.pop();
            
            
            else:
                result = False
                return result
        
        if (len(myStack) == 0):
            return True
        
        else:
            return False


s = "{[]}"
myObj = Solution()
answer = myObj.isValid(s)
print(answer)
