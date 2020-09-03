
#include <iostream>
using namespace std;

#include <map>

/*
	Intuition:  LeetCode's solution sliding window.  Good windows is represented by a window with two or less 
		    distinct characters [1,2].

		    Good window - rightPtr moves ahead
		    Bad window - rightPtr stops moving ahead
		    
		    Good window - leftPtr stops moving ahead
		    Bad window - leftPtr moves ahead

		    At a given point in time, one pointer moves while another stay fixed. 

	RunTime: O(N)
	Space Complexity: O(1)

*/

int lengthOfLongestSubstringTwoDistinct(string s)
{
    int result = 0;
    int leftPtr = 0;
    map<char, int> myMap;
    const int TWO = 2;
    
    for (int i = 0; i < s.size(); i++)
    {
        myMap[s[i]]++;
        
        if (myMap.size() <= TWO)
        {
            if (s.substr(leftPtr, i - leftPtr + 1).size() > result)
            {
                result = (int)s.substr(leftPtr, i - leftPtr + 1).size();
            }
        }
        
        else if (myMap.size() > TWO)
        {
            while (myMap.size() > TWO)
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
	string s = "ccaabbb";
	
	int answer =  lengthOfLongestSubstringTwoDistinct(s);

	cout << answer << endl;
 
	return 0;
}


