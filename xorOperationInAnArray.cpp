#include <iostream>
using namespace std;

int xorOperation(int n, int start)
{
    int result;
    
    if (n == 1)
    {
        return start;
    }
    
    result = start + (2 * 0);
    
    for (int i = 1; i < n; i++)
    {
        result = (result ^ (start + (2 * i)));
    }
    
    return result;
}

int main()
{
    int n, start;
    
    n = 4;
    start = 3;
    
    cout << xorOperation(n, start) << endl;

    return 0;
}

