
#include <iostream>
using namespace std;

#include <cmath>

int countOddsV1(int low, int high);
int countOddsV2(int low, int high);
int countOddsV3(int low, int high);

int main()
{
    int low = 2;
    int high = 29;
    
    int answer = countOddsV1(low, high);
    
    cout << answer << endl;
    
    return 0;
}

int countOddsV2(int low, int high)
{
    // O(N)
    // O(1)
    int start = ((low % 2) == 0) ? low + 1 : low;
    int count = 0;
    
    for (int i = start; i <= high; i = i + 2)
    {
        count++;
    }
    
    return count;
}

int countOddsV1(int low, int high)
{
    // O(1)
    // O(1)
    int start = (((low % 2) == 0) && (low < high)) ? low + 1 : low;
    int end = (((high % 2) == 0) && (high > low)) ? high - 1 : high;
    
    if (start == end && (start % 2) == 0)
    {
        return 0;
    }
    
    if (start == end && (start % 2) != 0)
    {
        return 1;
    }
    
    int count = 2;
    
    int result;
    
    result = floor((((end - 1) - (start + 1)) + 1) / 2) + count;
    
    return result;
}

int countOddsV3(int low, int high) 
{
	// O(1)
	// O(1)

        int length = high - low + 1;
        int result;
        
        if ((length % 2) == 0) 
        {
            result = length / 2;
        }
        
        else if ((length % 2) != 0)
        {
            if ((low % 2) == 0)
            {
                result = length / 2;
            }
            
            else if ((low % 2) != 0)
            {
                result = (length / 2) + 1;
            }
        }
        
        return result;
}

