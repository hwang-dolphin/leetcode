#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: Use two pointers, leftPtr and rightPtr.  Also use a two element window, chars[i - 1], chars[i]
		   acting as "good window or bad window".

	RunTime: O(N)
	Space Complexity: O(N)
*/

int compress(vector<char>& chars) 
    {
        vector<char> result;
        
        int left = 0;
        int right = 0;
        string tempCount;
        
        if (chars.size() == 1)
        {
            return chars.size();
        }
        
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i - 1] == chars[i])
            {
                right++;
            }
            
            if (chars[i - 1] != chars[i])
            {
                // calculation
                result.push_back(chars[left]);
                
                tempCount = to_string(right - left + 1);
                
                if (tempCount != "0" && tempCount != "1")
                {
                    for (int index = 0; index < tempCount.size(); index++)
                    {
                        result.push_back(tempCount[index]);
                    }
                }
        
                // update
                left = i;
                
                right = left;
                
                tempCount.clear();
            }
            
            if (i == chars.size() - 1 && chars[i - 1] == chars[i])
            {
                result.push_back(chars[left]);
                
                tempCount = to_string(right - left + 1);
                
                for (int index = 0; index < tempCount.size(); index++)
                {
                    result.push_back(tempCount[index]);
                }
                
                tempCount.clear();
            }
            
            else if (i == chars.size() - 1 && chars[i - 1] != chars[i])
            {
                result.push_back(chars[i]);
            }
        }
        
        for (int i = 0; i < result.size(); i++)
        {
            chars[i] = result[i];
        }
        
        chars.erase(chars.begin() + result.size(), chars.end());
        
        return chars.size();
        
    }

int main()
{
	vector<char> chars = {'a','b','b','b'};

	int answer = compress(chars);

	for (auto i: chars)
	{
		cout << i << " ";
	}

	cout << endl;
	cout << answer << endl;

	return 0; 	
}
