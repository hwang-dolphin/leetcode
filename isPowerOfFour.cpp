#include <iostream>
using namespace std;

#include <cmath>

bool isPowerOfFour(int num);

int main()
{
	bool answer = isPowerOfFour(5);

	cout << answer << endl;

}

bool isPowerOfFour(int num)
{
	// use of mathmatical formula
	// time complexity: O(1)
	// space complexity: O(1)
	
	double result;
        
        if (num <= 0)
        {
            return false;
        }
        
        result = log(num)/log(4);
        
        return (result == (int) result) ? true : false;
}
