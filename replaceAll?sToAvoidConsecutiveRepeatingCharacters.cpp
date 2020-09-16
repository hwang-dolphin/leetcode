#include <iostream>
using namespace std;

/*
	Intuition: Use ASCii table to get value of a = 97 and z = 122.  Whenever found 
		   a '?' then traverse from 97 - 122 to find the first interger not equal 
	           to its neighbor from left or neighbor from right.
	
	RunTime: O(N)

	Space Complexity: O(1)

*/


string modifyString(string s)
{
    if (s.size() == 1 && s[0] == '?')
    {
        s[0] = 'a';
        return s;
        
    }
    
    else if (s.size() == 1 && s[0] != '?')
    {
        return s;
    }
    
    
    
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            if (s[0] == '?')
            {
                for (int j = 97; j <= 122; j++)
                {
                    if (j != s[1])
                    {
                        s[i] = j;
                        break;
                    }
                }
            }
            
            continue;
        }
        
        if (i == s.size() - 1)
        {
            if (s[s.size() - 1] == '?')
            {
                for (int j = 97; j <= 122; j++)
                {
                    if (j != s[s.size() - 2])
                    {
                        s[i] = j;
                        break;
                    }
                }
            }
            
            continue;
        }
        
        if (s[i] == '?')
        {
            for (int j = 97; j <= 122; j++)
            {
                if (j != s[i - 1] && j != s[i + 1])
                {
                    s[i] = j;
                    break;
                }
            }
        }
    }
    
    
    
    return s;
}

int main()
{
    string s = "??s";
    string a = modifyString(s);
    cout << a << endl;
    
    return 0;
}
