#include <iostream>
using namespace std;

#include <map>


/*
	Intuition:  Simple checking if a word can be a palindrome by following the rule: a permutation 
		    of a palindrome has each letters frequency in even except for at most one letter	
		    which could be odd.


	RunTime: O(N), N the size of string s 
	Space Complexity: O(N), N the size of string s
*/

bool canPermutePalindrome(string s) 
{
        map<char, int> myMap;
        int oddCount = 0;
        bool result = true;
      
        
        for (int i = 0; i < s.size(); i++)
        {
            myMap[s[i]]++;
        }
        
        for (auto i: myMap)
        {
            if (i.second % 2 != 0)
            {
                oddCount++;
            }
            
            if (oddCount > 1)
            {
                result = false;
                break;
            }
        }
        
        return result;
}

int main()
{
	string s = "carerac";	
	bool answer = canPermutePalindrome(s);

	cout << answer << endl;

	return 0;
}
