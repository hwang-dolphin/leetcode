
#include <iostream>
using namespace std;

int getSum(int a, int b)
{
    // sum of (a ^ b) represented as noCarry plus carry represented as ((noCarry & carry) << 1)
    // until noCarry becomes 0
    int noCarryTemp;
    
    unsigned int noCarry, carry;
    
    noCarry = (a ^ b);
    carry = (unsigned int)(a & b) << 1;
    
    while (carry)
    {
        noCarryTemp = (carry ^ noCarry);
        
        carry = (noCarry & carry) << 1;
        
        noCarry = noCarryTemp;
    }
    
    return noCarry;
}

int main()
{
    int a, b;
    
    a = -78;
    b = 1;
    
    int answer = getSum(a, b);
    
    cout << answer << endl;
   
    return 0;
}

