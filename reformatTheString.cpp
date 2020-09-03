#include <iostream>
using namespace std;

#include <queue>

/*
	Intuition:  Separate alphabet and digits into their own storage space.  These two separete
		    storage should not have absolute difference equal or greater than 2.

	            Decide who has more elements, the alphabet array or the digit array.  Whichever
		    has more is the one that is first push_back to the result string.

		    Loop while until both arrays are empty.  If the last character in the result string was
		    a digit then push_back a character and if the last character in the result string was a 
		    character then push_back a digit.  

	RunTime: O(N)

	Space Complexity: O(N)

*/


string reformat(string s) 
    {
        queue<char> characterVect;
        queue<int> digitVect;
        
        string result;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                digitVect.push(s[i] - '0');
            }
            
            else
            {
                characterVect.push(s[i]);
            }
        }
        
        if (abs((int)digitVect.size() - (int)characterVect.size()) >= 2)
        {
            return "";
        }
        
        if ((int)characterVect.size() >= (int)digitVect.size())
        {
            result.push_back(characterVect.front());
            characterVect.pop();
        }
        
        else if ((int)digitVect.size() > (int)characterVect.size())
        {
            result.push_back(digitVect.front() + '0');
            digitVect.pop();
        }
        
        int index = 0;
        
        while ((int)digitVect.size() > 0 || (int)characterVect.size() > 0)
        {
            if (isdigit(result[index]))
            {
                result.push_back(characterVect.front());
                characterVect.pop();
            }
                
            else 
            {
                result.push_back(digitVect.front() + '0');
                digitVect.pop();
            }
        
            index++;
        }
        
        return result;
    }




int main()
{
	string s = "a0b1c2";
	string answer = reformat(s);

	cout << answer << endl;

	return 0;
}
