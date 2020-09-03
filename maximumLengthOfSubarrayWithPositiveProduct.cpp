#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Any subarray with even number of negative values and no zeros and including positive numbers
	            would produce a positive multiplication.  Two pass using this idea, but my style of coding 
		    requires a second pass to catch some edge cases at the ending.  For example, first pass
		    would not  catch [-1,2,3,4].  Only the second pass loop would catch this bug.

	RunTime: O(N)
	Space Complexity: O(1)	
*/


int getMaxLen(vector<int>& nums) 
    {
        int negativeCounter = 0;
        int positiveCounter = 0;
        
        int maximumLength = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                negativeCounter = 0;
                positiveCounter = 0;
            }
            
            else if (nums[i] > 0)
            {
                positiveCounter++;
            }
            
            else if (nums[i] < 0)
            {
                negativeCounter++;
            }
            
            if (negativeCounter % 2 == 0 && (positiveCounter + negativeCounter) > maximumLength)
            {
                maximumLength = (positiveCounter + negativeCounter);
            }
        }
        
        negativeCounter = 0;
        positiveCounter = 0;
        
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                negativeCounter = 0;
                positiveCounter = 0;
            }
            
            else if (nums[i] > 0)
            {
                positiveCounter++;
            }
            
            else if (nums[i] < 0)
            {
                negativeCounter++;
            }
            
            if (negativeCounter % 2 == 0 && (positiveCounter + negativeCounter) > maximumLength)
            {
                maximumLength = (positiveCounter + negativeCounter);
            }
        }
        
        
        return maximumLength;
    }

int main()
{
	vector<int> nums = {0,1,-2,-3,-4};

	int answer = getMaxLen(nums);

	cout << answer << endl;

	return 0;
}
