
#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Very simple intuition, make sure the total sum of the array is a divisible by 3
		    in other words (totalSum % 3 == 0).  Find the equal sum value (totalSum / 3).
		    Count how many parts with equal sum has been found.  The trick here is simply
		    knowing that finding only 2 or less will always return false because not enough
		    equal parts.  However if found 3 or more parts will result in true because the other
		    parts that remain can be rearranged in three groups.

	RunTime: O(N)
	Space Complexity: O(1)
*/


bool canThreePartsEqualSum(vector<int>& A) 
    {
        long long int equalSum = 0;
        bool result = false;
        
        for (auto i: A)
        {
            equalSum = equalSum + i;
        }
        
        if (equalSum % 3 != 0)
        {
            return false;
        }
        
        equalSum = equalSum / 3;
      
        int foundCounter = 0;
        long long int eachSum = 0;
        
        for (int i = 0; i < A.size(); i++)
        {
            eachSum = eachSum + A[i];
            
            if (eachSum == equalSum)
            {
                foundCounter++;
                eachSum = 0;
            }
        }
        
        if (foundCounter < 3)
        {
            result = false;
        }
        
        else if (foundCounter >= 3)
        {
            result = true;
        }
   
        return result;
    }

int main()
{
	vector<int> A = {10,-10,10,-10,10,-10,10,-10};
	bool answer = canThreePartsEqualSum(A);

	cout << answer << endl; 
	
	return 0;
}

