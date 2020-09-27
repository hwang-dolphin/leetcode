#include <iostream>
using namespace std;

/*
	Intuition:  Delete all characters in string 't' which are found in string 's'.
		    By default, only one character will remain.  Return this only remaining 
		    character.

	RunTime: O(N)
	Space complexity: O(1)
*/



char findTheDifference(string s, string t)
{
    for (int i = 0; i < s.size(); i++)
    {
        t.erase(t.find(s[i]), 1);
    }
   
    return t[0];
}

int main()
{
    string s = "abcd";
    string t = "abcde";
    
    char answer = findTheDifference(s, t);
    
    cout << answer << endl;
    
    return 0;
}
