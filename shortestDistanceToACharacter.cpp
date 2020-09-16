#include <iostream>
using namespace std;

#include <vector> 

/*
	Intuition: two pointers, previous and i.  previousPtr gets set when S[i] equal to C.
		   two passes to fix the bug of the first pass.
		   Trick here is just to initialize pointer previousPtr properly so
		   it gives correct answer and doesn't overflow.
		
		   -20000 and 20000 was used because INT_MAX and INT_MIN would have problems
		   of overflow.  Since the problem states S string length is in [1, 10000],
		   -20000 and 20000 is customINT_MAX and customINT_MIN to solve problem
		   of overflow and underflow.


	RunTime: O(N)
	Space Complexity: O(1)
*/



vector<int> shortestToChar(string S, char C) 
    {

        vector<int> result(S.size(), INT_MAX);
        
        int previous = -20000;
        
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                previous = i;
                result[i] = 0;
            }
            
            else
            {
                result[i] = i - previous;
            }
        }
 
        previous = 20000;
        
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == C)
            {
                previous = i;
                result[i] = 0;
            }
            
            else
            {
                result[i] = min(previous - i, result[i]);
            }
        }
        
        return result;
    }

int main()
{
	string S = "loveleetcode";
	char C = 'e';

	vector<int> answer = shortestToChar(S, C);

	for (auto i: answer)
	{
		cout << i << " ";
	}

	cout << endl;	
	
	return 0;
}
