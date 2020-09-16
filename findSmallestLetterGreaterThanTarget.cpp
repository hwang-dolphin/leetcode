#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: Linear search for first character greater than target.
		   If not found, then return letters[0]

	RunTime: O(N)
	Space Complexity: O(1)

*/

char nextGreatestLetter2(vector<char>& letters, char target) 
    {
        char x;
        
        int i = 0;
        int iTemp = 0;
        while (true)
        {
            iTemp = i;
            i =  i = i % letters.size();
       
            if (letters[i] % 123 > target || iTemp >= letters.size())
            {
                x = letters[i];
                break;
            }
            
            i++;
          
        }
        
        return x;
    }

char nextGreatestLetter(vector<char>& letters, char target)
{
	// 'A' custom NULL
	char result = 'A';
        
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                result = letters[i];
                break;
            }
        }
        
        result = (result == 'A') ? letters[0] : result;
        
        return result;	
}

int main()
{
	vector<char> letters = {'c', 'f', 'j'};
	char target = 'k';

	char answer = nextGreatestLetter(letters, target);

	cout << answer << endl;	

	return 0;
}
