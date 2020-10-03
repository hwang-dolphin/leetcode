class Solution:
    def isPalindrome(self, x: int) -> bool:
        # edge cases:  all negative numbers are not palindrome
        if (x < 0):
            return False
        
        # case last numbers are 0 example 10, 20 etc
        if (int(x % 10) == 0 and x != 0):
            return False
        
        else:
            # math formula that reverts only half to avoid overflow problem
            reversedNumber = 0
            
            while (x > reversedNumber):
                reversedNumber = int(reversedNumber * 10) + int(x % 10)
                x = int(x / 10)
            
        # in palindrome the middle in odd length numbers dont matter
        return (x == reversedNumber or x == int(reversedNumber / 10))


myObj = Solution()
print(myObj.isPalindrome(-121))

