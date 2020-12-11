class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        result = False
        counter = 0
        
        myMap = {}
    
        if (len(A) != len(B) or
            len(A) == 0 and len(B) == 0):
        
            return False
        
        
        if (A == B and 
           (len(A) >= 2 and len(B) >= 2)):
        
            for i in range(0, len(A)):
                if (A[i] not in myMap):
                    myMap[A[i]] = 1
                else:
                    myMap[A[i]] = myMap[A[i]] + 1
         
            for key, value in myMap.items():
                if (value >= 2):
                    result = True
                    break;
                
            return result
        
        
        
        for i in range(0, len(A)):
            if (A[i] != B[i]):
                counter = counter + 1
            
                if (counter == 1):
                    first = i
                
                elif (counter == 2):
                    second = i
                
            if (counter > 2):
                result = False
                break
            
        if (counter == 2):
            """
				create a list from string A
				manipulate the list 
				and convert the list into another string
            """
            aList = list(A)
            aList[first] = A[second]
            aList[second] = A[first]
     
            if (''.join(aList) == B):
                result = True;
            
        return result
        

myObj = Solution()
answer = myObj.buddyStrings("ab", "ba")

print(answer)
