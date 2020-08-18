
#include <iostream>
using namespace std;

/*
Intuition: Visualize it graphically, geometrically way.  Given n, the array that forms, will 
	   be a linear line (hypotenuse of a triangle).  Measure its end pooints y values and 
	   the height of the triangle will be formed.  Work with only half of this newHeight of the triangle.
	   The answer will be graphically the sum of heights of half the original triangle.  
	   Sum the newHeights decrementing "2" for each iteration.


RunTime complexity: O(N)
Space Complexity: O(1)

*/



int minOperations(int n) 
    {
        int yHypotenuseStart = (2 * 0) + 1;
        int yHypotenuseEnd = (2 * (n - 1)) + 1;
    
        int height = yHypotenuseEnd - yHypotenuseStart;
    
        int newHeight = height / 2;
    
        int result = 0;
    
        while (newHeight > 0)
        {
            result = result + newHeight;
        
            newHeight = newHeight - 2;
        }
    
        return result;
    }


int minOperations2(int n) 
    {
	// mathmatical version
	// Intuition:  use math formulas to sum first n numbers of even or odd numbers
	// sum of all first n odd numbers: n^2
	// sum of all first n even numbers: n*(n+1)
	// RunTime: O(1)
	// Space: O(1)

        int result;
        int nHalf = n / 2;
        
        if (n % 2 == 0)
        {
            // sum of all first nHalf odd numbers
            result = nHalf * nHalf;
        }
        
        else
        {
            // sum of all first nHalf even numbers
            result = (nHalf)*(nHalf + 1);
        }
        
        return result;
    }



int main()
{
	int n = 6;
	int answer = minOperations(n);

	cout << answer << endl;

	return 0;
}
