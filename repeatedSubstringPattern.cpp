#include <iostream>
using namespace std;

 
/*
	According to LeetCode, one intuitive idea is to concatenate its input doubling it.
	Then, get the substring of this "double string" beginning at element index 1 to doubledString.size() - 2 (both inclusi		ve) [1, doubledString.size() - 2].  From this substring check if it conatains the given string.
	The result will the desired result.

*/


  bool repeatedSubstringPattern(string s) 
    { 
        return ((s + s).substr(1, 2 * s.size() - 2).find(s) == string::npos) ? false : true;
    }


int main()
{
	string s = "aba";
	bool answer = repeatedSubstringPattern(s);

	cout << answer << endl;

	return 0;
}
