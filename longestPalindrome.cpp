#include <iostream>
using namespace std;

#include <map>

/*
	Intuition: Greedy.  The longest palindrome will be formed by as many pairs of equal letters
			    as possible.  In case there is an odd set of letters, count as much pairs
			    as possible and add only one more letter as "unique" to the result.

	RunTime: O(N)	
*/


int longestPalindrome(string s) 
    {
        int result = 0;
        map<char, int> myMap;
        bool addAnOdd = false;
        
        if (s.size() <= 1)
        {
            return s.size();
        }
        
        else
        {
            for (auto i: s)
            {
                myMap[i]++;
            }
            
            for (auto i: myMap)
            {
                if (i.second % 2 == 0)
                {
                    result = result + i.second;
                }
                
                else if (i.second % 2 != 0)
                {
                    result = result + i.second - 1;
                    addAnOdd = true;
                }
            }
        }
        
        return (addAnOdd == true) ? result + 1 : result;
    }

int main()
{
	string s = "abccccdd";

	int answer = longestPalindrome(s);

	cout << answer << endl;   	

	return 0;
}
