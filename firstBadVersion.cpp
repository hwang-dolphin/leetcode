

#include <iostream>
using namespace std;

int firstBadVersion(int);

int main()
{
    int n = 5;
    int badVersion = 4;
    
    int answer = firstBadVersion(n);
    
    cout << answer << endl;
    
    return 0;
}

int firstBadVersion(int n)
{
    int result;
    
    int left = 1;
    int right = n;
    int middle;
    
    if (isBadVersion(1) == true)
    {
        result = 1;
        return result;
    }
    
    if (isBadVersion(n) == true && isBadVersion(n - 1) == false)
    {
        result = n;
        return result;
    }
    
    while (left <= right)
    {

	// a good way for middle not to overflow
        middle = ((right - left) / 2) + left;
        
        if (isBadVersion(middle) == true && isBadVersion(middle - 1) == false)
        {
            result = middle;
            break;
        }
        
        else if (isBadVersion(middle) == false)
        {
            left = middle + 1;
        }
        
        else if (isBadVersion(middle) == true)
        {
            right = middle - 1;
        }
    }
    
    return result;
}


