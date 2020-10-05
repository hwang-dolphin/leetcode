from typing import List

"""
	Intuition:  Sort both list of children and cookies.  Eliminate the cookies that
				dont satisfy any child apetite.  Count those that do satisfy their appetite
			    and move on to next child.  The program should end as soon as either we
				have finish with cookies or children.

	RunTime: O(N Log N)
	Space Complexity: O(1)
"""

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
     
        counter = 0;
        childPtr = 0;
        
        for i in range(0, len(s)):
            if (s[i] < g[childPtr]):
                continue;
            
            elif (s[i] >= g[childPtr]):
                counter += 1
                childPtr += 1
                
                if (childPtr >= len(g)):
                    break;
                
        return counter;


g = [1,2]
s = [1,2,3]

myObj = Solution()
answer = myObj.findContentChildren(g, s)
print(answer)
