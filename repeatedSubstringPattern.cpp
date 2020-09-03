#include <iostream>
using namespace std;

#include <vector>
 
/*

	Intuition of V2:  According to LeetCode, one intuitive idea is to concatenate its input doubling it.
	Then, get the substring of this "double string" beginning at element index 1 to doubledString.size() - 2 (both inclusi		ve) [1, doubledString.size() - 2].  From this substring check if it conatains the given string.
	The result will the desired result.


	Intuition of V1:  Brute force, Use two pointers left and right to find all patterns from smallest to biggest patterns.
			  Use a vector to store all these patterns found.

			  Go through each of them and check if they are valid by the rules of the problem, they 
			  should be repetivive patterns not just one pattern.

	RunTime: O(N)
	Space Complexity: O(N)	

*/


  bool repeatedSubstringPatternV2(string s) 
    { 
        return ((s + s).substr(1, 2 * s.size() - 2).find(s) == string::npos) ? false : true;
    }

bool repeatedSubstringPattern(string s) 
    {
        string sTemp = s;
        
        vector<string> patternVect;
        
        bool result;
        
        for (int left = 0, right = s.size() - 1; left < s.size(), right >= 0; left++, right--)
        {
            if (left > right)
            {
                break;
            }
            
            else if ((left == right) && s.substr(0, left - 0 + 1) != s.substr(right, string::npos))
            {
                break;
            }
            
            if (s.substr(0, left - 0 + 1) == s.substr(right, string::npos))
            {
                patternVect.push_back(s.substr(0, left - 0 + 1));
            }
        }
        
        if (patternVect.empty())
        {
            return false;
        }
        
        for (auto i: patternVect)
        {
            int numberOfCopies = 0;
            sTemp = s;
            size_t found = sTemp.find(i);
        
            while (found != string::npos)
            {
                sTemp.erase(found, (int)i.size());
            
                found = sTemp.find(i);
            
                numberOfCopies++;
            }
        
            result = (sTemp.empty() && numberOfCopies > 1) ? true : false; 
            if (result)
            {
                break;
            }
        }
        
        return result;
    }



int main()
{
	string s = "ababababab";
	bool answer = repeatedSubstringPattern(s);

	cout << answer << endl;

	return 0;
}
