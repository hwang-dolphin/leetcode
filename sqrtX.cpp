#include <iostream>
using namespace std;

/*
	Intuition:  Simple loop and  track of index variable and take care of overflows.
	
	RunTime: O(Sqrt(x))
	Space Complexity: O(1)
	
*/


int mySqrt(int x) 
    {

	// important to put unsigned int here or long long int 
	// because int is not big enough
	// compiler places the result to an invisible bucket before placing the result to the 
	// actual result variable
        unsigned int index = 0;


        long long int result;
        
        while (true)
        {
            result = index * index;
            
            if (result == x)
            {
                break;
            }
            
            else if (result > x)
            {
                index--;
                break;
            }
            
            index++;
        }
   
        return index;
    }


int main()
{
	int x = 2147483647;

	int answer = mySqrt(x);

	cout << answer << endl;

	return 0;
}
