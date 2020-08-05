#include <iostream>
using namespace std;

int addDigits(int num)
{
    int remainder = 0;
    
    while (num > 0)
    {
        remainder = remainder + (num % 10);
        num = num / 10;
        
        if (num == 0 && remainder >= 10)
        {
            num = remainder;
            remainder = 0;
        }
        
        else if (num == 0 && remainder < 10)
        {
            num = remainder;
            break;
        }
    }
    
    return num;
}

int main()
{    
    int answer = addDigits(556);
    
    cout << answer << endl;
    
    return 0;
}

