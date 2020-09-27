#include <iostream>
using namespace std;

#include <map>

/*
	Intuition: Sliding Window with two-pointers.  Keep a current count of the character 
		   with most presence in the current window.  The rightPtr should continue
		   moving forward as long as "size of current window - most character count" <= "k".
	           Check if the current window is greater than "longest".  
		   If "size of current window - most character count" > "k", then update the helper map
		   and move the leftPtr forward.

	RunTime: O(N)
	Space Complexity: O(N)		   

*/


int characterReplacement(string s, int k)
{
    map<char, int> myMap;
    int longest = 0;
    int mostChar = 0;
    
    int leftPtr = 0;

    for (int rightPtr = 0; rightPtr < s.size(); rightPtr++)
    {
        myMap[s[rightPtr]]++;
        
        for (auto i: myMap)
        {
            if (i.second > mostChar)
            {
                mostChar = i.second;
            }
        }
        
        if ((rightPtr - leftPtr + 1) -  mostChar <= k)
        {
            if ((rightPtr - leftPtr + 1) > longest)
            {
                longest = (rightPtr - leftPtr + 1);
            }
        }
        
        else
        {
            if (myMap[s[leftPtr]] == 1)
            {
                myMap.erase(s[leftPtr]);
            }
            
            else
            {
                myMap[s[leftPtr]]--;
            }
            
            leftPtr++;
        }
        
        mostChar = 0;
    }
    
    return longest;
}

int main()
{
    string s = "ABBBACCD";
    int k = 2;
    
    int answer = characterReplacement(s, k);
    
    cout << answer << endl;
    
    return 0;
}

