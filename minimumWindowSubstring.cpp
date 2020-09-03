#include <iostream>
using namespace std;

#include <map>


/*
	Intuition:  This problem was very hard to finish by myself because of the runtime.  
		    Use two pointers, left and right, to find a "good window that has all characters 
		    of "t" string.  Bad window right pointer moves ahead; Good window left pointer moves ahead.

		    The most difficult was to code the part where we need to know if a substring contains all characters
		    or not in a fast way.  The idea was to use two maps of characters frequency.  One map for t string
		    frequency and another map for current window character frequency.  Also use a helper int variable
		    to decide how many characters is need to match.  It was like a play with these to maps of frequency
		    to get the right code.

	RunTime: O(N)
	Space Complexity: O(N).	

*/

string minWindow(string s, string t)
{
    string result = "";
    
    int leftPtr = 0;
    int totalCharsRequiredToMatch = (int)t.size();
    int smallestWindow = INT_MAX;
    
    
    map<char, int> currWindowMap;
    map<char, int> tMap;
    
    for (int i = 0; i < t.size(); i++)
    {
        tMap[t[i]]++;
        
        currWindowMap.insert(make_pair(t[i], 0));
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        // expanding the window
        currWindowMap[s[i]]++;
        
        if (tMap.find(s[i]) != tMap.end() && currWindowMap[s[i]] <= tMap[s[i]])
        {
            totalCharsRequiredToMatch--;
        }
        
        // good window found
        if (totalCharsRequiredToMatch == 0)
        {

            // contracting the window
            while (totalCharsRequiredToMatch == 0)
            {
                if (i - leftPtr + 1 < smallestWindow)
                {
                    result = s.substr(leftPtr, i - leftPtr + 1);
                    smallestWindow = i - leftPtr + 1;
                }
                
                
                if (tMap.find(s[leftPtr]) == tMap.end())
                {
                    if (currWindowMap[s[leftPtr]] > 1)
                    {
                        currWindowMap[s[leftPtr]]--;
                    }
                    
                    else if (currWindowMap[s[leftPtr]] == 1)
                    {
                        currWindowMap.erase(s[leftPtr]);
                    }
                }
                
                else if (tMap.find(s[leftPtr]) != tMap.end())
                {
                    currWindowMap[s[leftPtr]]--;
                    
                    if (currWindowMap[s[leftPtr]] < tMap[s[leftPtr]])
                    {
                        totalCharsRequiredToMatch++;
                    }
                }
                
                leftPtr++;
            }
        }
    }
    
    
    return result;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    
    string answer = minWindow(s, t);
    
    cout << answer << endl;
    
    return 0;
}

