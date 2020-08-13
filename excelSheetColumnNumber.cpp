#include <iostream>
using namespace std;

#include <cmath>

/*
Intuition:  It is an accumulator.  The trick is to find the formula for each letter
which is "(s[i] - 64) * pow(26, s.size() - 1)" for a traversal from left to right.
Each time it advances from left to right, decrease the exponent by one number.
Keep accumulating until finish all letters.

Runtime complexity: O(n)
Space Complexity: O(1)
*/


int titleToNumber(string s)
{
    int answer = 0;
    int index = 0;
    
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        answer = answer + ((s[i] - 64) * pow(26, index));
        index++;
    }
    
    return answer;
}

int main()
{
    string s = "AB";
    
    int result  = titleToNumber(s);
    
    cout << result  << endl;
    
    return 0;
}
