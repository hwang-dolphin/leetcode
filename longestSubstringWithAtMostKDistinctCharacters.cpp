#include <iostream>
using namespace std;

#include <map>

/*
	Intuition:  Very same concept as the problem "longestSubstringWithAtMostTwoDistinctCharacters".
		    Use sliding window with two pointers: leftPtr and rightPtr.  Only one pointer will
		    move at a given time, the other pointer will remain fixed.  

		    When the pointers find a "good window" the right pointer moves ahead until the "good window"
		    is no longer "good window".  The left pointer will move ahead while a "good window" has not been found.


	RunTime: O(N)
	Space Complexity: O(K)
*/


int lengthOfLongestSubstringKDistinct(string s, int k)
{
    int result = 0;
    int leftPtr = 0;
    map<char, int> myMap;
    
    for (int i = 0; i < s.size(); i++)
    {
        myMap[s[i]]++;
        
        if (myMap.size() <= k)
        {
            if (s.substr(leftPtr, i - leftPtr + 1).size() > result)
            {
                result = (int)s.substr(leftPtr, i - leftPtr + 1).size();
            }
        }
        
        else if (myMap.size() > k)
        {
            while (myMap.size() > k)
            {
                if (myMap[s[leftPtr]] == 1)
                {
                    myMap.erase(s[leftPtr]);
                }
                
                else if (myMap[s[leftPtr]] > 1)
                {
                    myMap[s[leftPtr]]--;
                }
                
                leftPtr++;
                
                if (s.substr(leftPtr, i - leftPtr + 1).size() > result)
                {
                    result = (int)s.substr(leftPtr, i - leftPtr + 1).size();
                }
            }
        }
    }
    
    return result;
}


int main()
{
	string s = "eceba";
	int k = 2;
   	int answer = lengthOfLongestSubstringKDistinct(s, k);
    
    	cout << answer << endl;

	return 0;
}

