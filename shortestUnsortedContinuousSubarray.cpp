
#include <iostream>
using namespace std;

#include <vector>

/*
Intuition:  Using sorting.  Make a copy of given vector and sort it.  Two pass loops to find leftPtr
and rightPtr.  The first element not equal from numsVector and numsCopyVector is the leftPtr.
Second pass traverse from last element, the first element not equal from numsVector and numCopyVector
is the rightPtr.

RunTime Complexity: NLog(n)
Space Complexity: O(1)
*/

int findUnsortedSubarray(vector<int>& nums) 
    {
        int answer;
        int leftPtr = -1;
        int rightPtr = -1;
        
        vector<int> numsCopy = nums;
        
        if (nums.size() == 1)
        {
            answer = 0;
        }
        
        else
        {
            sort(numsCopy.begin(), numsCopy.end());
            
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != numsCopy[i])
                {
                    leftPtr = i;
                    break;
                }
            }
            
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] != numsCopy[i])
                {
                    rightPtr = i;
                    break;
                }
            }
            
            if (leftPtr == -1 && rightPtr == -1)
            {
                answer = 0;
            }
            
            else
            {
                answer = rightPtr - leftPtr + 1;
            }
        }
        
        return answer;
    }

int main()
{
	vector<int> nums = {2,6,4,8,10,9,15};

	int answer = findUnsortedSubarray(nums);

	cout << answer << endl;

	return 0;	
}
