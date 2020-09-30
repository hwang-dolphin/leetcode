#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	Intuition:  Sort array in ascending order and use two pointer window.
		    Simple window comparing the current element with the previous element.
		    If both elements are equal, then increase the current element by one and add
		    the result counter by one.  If current element is less than previous element,
		    then set the current element to a number higher than previous element
		    by only one and add the difference between these two numbers plus one to the 
		    result counter.

	RunTime:    O(N LOG N)
	Space Complexity: O(1)    
*/


int minIncrementForUnique(vector<int>& A) 
    {
        int result = 0;
        
        if (A.size() <= 1)
        {
            return 0;
        }
        
        sort(A.begin(), A.end());
        
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == A[i - 1])
            {
                result++;
                A[i] = A[i] + 1;
            }
            
            else if (A[i] < A[i - 1])
            {
                result = result + (A[i - 1] - A[i]) + 1;
                A[i] = A[i] + (A[i - 1] - A[i]) + 1;
            }
        }
        
        return result;
    }

int main()
{
	vector<int> A = {3,2,1,2,1,7};

	int answer = minIncrementForUnique(A);

	cout << answer << endl;

	return 0;
}
