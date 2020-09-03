
#include <iostream>
using namespace std;

#include <vector>
#include <climits>

/*
	Intuition: The data structure to store the datas should be a two-dimensional array because
	           we need to take care of repeating characters.  The algorithm should be traversing
		   through this two-dimensional array but going through all rows for each column.
		   Column is outer loop and row is inner loop.  If value is 0, not common to all strings
		   then break.  Find the minimum number through the loop.  If minimum number is "2" that means
		   that letter is common to all strings twice; the same letter repeated twice.


	RunTime: O(26 * N), O(N)    
	Space complexity:  O(N)
*/

vector<string> commonChars(vector<string>& A)
{
    int myArray[100][26];
    memset(myArray, 0, sizeof(myArray));
    
    vector<string> result;
    
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            int col = A[i][j] - 'a';
            
            myArray[i][col]++;
        }
    }
    
    int minimum = INT_MAX;
    char letter;
    string letterStr;
    
    for (int col = 0; col < 26; col++)
    {
        for (int row = 0; row < A.size(); row++)
        {
            if (myArray[row][col] == 0)
            {
                break;
            }
            
            else
            {
                if (myArray[row][col] < minimum)
                {
                    minimum = myArray[row][col];
                }
                
                if (row == A.size() - 1)
                {
                    letter = col + 'a';
                    letterStr = letter;
                    
                    for (int i = 0; i < minimum; i++)
                    {
                        result.push_back(letterStr);
                    }
                }
            }
        }
        
        minimum = INT_MAX;
    }
    
    return result;
    
}

int main()
{
    vector<string> A = {"cool","lock","cook"};
    
    vector<string> answer = commonChars(A);

    for (auto i: answer)
    {
        cout << i << endl;
    }
    
    return 0;
}
