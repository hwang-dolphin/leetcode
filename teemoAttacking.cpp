#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  This problem is an accumulator of time.  Two collapsing time counts as "one unit of time"
		    not "double unit of time".
		
		    ** (Not a good question, bit hard to understand) **

	RunTime: O(N)

	Space Complexity: O(1)	
*/


int findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    int result = 0;
    
    if (timeSeries.size() == 0)
    {
        return 0;
    }
    
    for (int i = 1; i < timeSeries.size(); i++)
    {
        if (timeSeries[i] - timeSeries[i - 1] >= duration)
        {
            result = result + duration;
        }
        
        else
        {
            result = result + (timeSeries[i] - timeSeries[i - 1]);
        }
    }
    
    result = result + duration;
    
    return result;
}

int main()
{
    vector<int> timeSeries = {3,6,5,8,19,26};
    int duration = 27;

    int answer = findPoisonedDuration(timeSeries, duration);
    
    cout << answer << endl;
    
    return 0;
}


