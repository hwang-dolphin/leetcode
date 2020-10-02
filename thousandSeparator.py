class Solution:
    def thousandSeparator(self, n: int) -> str:
        counter = 1
        """
        list of string
        vector<char>
        """
        myList = []
        
        if (n == 0):
            return "0"
        
        while (n > 0):
            if (counter > 3):
                myList.insert(0, ".")
                counter = 1
                
            myList.insert(0, str(int(n % 10)))
      
            counter = counter + 1
            n = int(n / 10)
        
        """"
        python's way of converting a list of string 
        into only one string
        """
        return "".join(myList)
         



      
n = 123456789
myObj = Solution()
print(myObj.thousandSeparator(n))
