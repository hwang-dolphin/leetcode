
#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <sstream>

/*
	Intuition: This one was a tough one.  Leetcode's solution focus mapping.  Playing with a map.
		   Assigning both characters and str word to the map as key and their corresponding 
		   i element value as map value.  If not found, add key and value.  Key are each letter
		   in pattern and value its i element value; another key is str word as key and same i element
		   value as value.  At end, check if both keys have same values.  Automatically they should
		   have different values if it is out of pattern.

	RunTime: O(N)
	Space Complexity: O(N).

*/


bool wordPattern(string pattern, string str) 
    {
        map<string, int> indexMap;
        vector<string> strVect;
        stringstream ss;
        string temp;
        
        ss << str;
        
        while(getline(ss, temp, ' '))
        {
            strVect.push_back(temp);
        }
        
        if (strVect.size() != pattern.size())
        {
            return false;
        }
        
        for (int i = 0; i < strVect.size(); i++)
        {
	    // toupper is like taking care of a test case
	    // since both pattern and str contains only lowercase letters
	    // then the program would not work correctly if both had same lower cases letters
	    // toupper is to make then different in cause they come all the same
            string c;
            c.push_back(toupper(pattern[i]));
            
            string w = strVect[i];
            
            if (indexMap.find(c) == indexMap.end())
            {
                indexMap.insert(make_pair(c, i));
            }      
            
            if (indexMap.find(w) == indexMap.end())
            {
                indexMap.insert(make_pair(w, i));
            } 
            
            if (indexMap[c] != indexMap[w])
            {
                return false;
            }
            
            c.clear();
        }
        
        return true;
    }

int main()
{
	string pattern = "abc";
	string str = "b c a";

	bool answer = wordPattern(pattern, str);

	cout << answer << endl;	

	return 0;
}
