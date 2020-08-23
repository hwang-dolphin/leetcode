
#include <iostream>
using namespace std;

#include <string>


/*
Intuition:  Just use naive approach.  Traverse through each digit of the number and carefully
	    inserting a dot every time we pass through 3 digits.

RunTime: O(N), N refering to the amount of digits the number contains
Space Complexity: O(1)
*/

string thousandSeparator(int n)
{
    // some compilers requires "size_t" in "insert" function otherwise giver ambiguious error

    string result;
    int counter = 1;
    
    if (n == 0)
    {
        return "0";
    }
    
    while (n > 0)
    {
        if (counter > 3)
        {
            result.insert((size_t)0, (size_t)1, '.');
            counter = 1;
        }
        
        result.insert((size_t)0, (size_t)1, (n % 10) + '0');
        
        n = n / 10;
        counter++;
    }
    
    return result;
}

int main()
{
	string answer = thousandSeparator(123456789);

	cout << answer << endl;

	return 0;
}
