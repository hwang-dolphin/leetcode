#include <iostream>
using namespace std;

#include <cmath>

bool isPowerOfFour(int num);
bool isPowerOfFourV2(int num);

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


bool isPowerOfFourV2(int num)
{
    // Using bit mask:  power of four has only one bit set at an even bit position (based zero)
    // reject negative numbers

    // runtime: O(1)
    // space complexity: O(1) 

    bool result = true;
    
    int leftMost;
    int rightMost;
    
    
    if (num < 0)
    {
        return false;
    }
    
    for (int i = 0; i < 32; i++)
    {
        if (((1 << i) & num) != 0)
        {
            leftMost = i;
            break;
        }
    }
    
    for (int i = 31; i >= 0; i--)
    {
        if (((1 << i) & num) != 0)
        {
            rightMost = i;
            break;
        }
    }
    
    if (leftMost == rightMost)
    {
        for (int i = 1; i < 32; i = i + 2)
        {
            if (((1 << i) & num) != 0)
            {
                result = false;
                break;
            }
        }
    }
    
    else
    {
        result = false;
    }

    return result;
}

