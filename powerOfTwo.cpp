
#include <iostream>
using namespace std;

#include <cmath>

bool isPowerOfTwo(int);

int main()
{
    int n = 16;
    
    bool answer = isPowerOfTwo(n);
    
    cout << answer << endl;
    
    return 0;
}

bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    
    double exponent = log2(n);
    
    return (exponent == (int)exponent) ? true : false;
}


