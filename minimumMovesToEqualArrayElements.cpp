
#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  The answer is the mathmatical formula sum of each element minus the minimum number (offset).
		    In the code, the first loop is to find the offset value.  The second loop is to apply 
		    this idea.

	RunTime: O(N)

	Space Complexity: O(1)
*/


int minMoves(vector<int>& nums) 
    {
        int offset = INT_MAX;
        int result = 0;
        
        if (nums.size() == 1)
        {
            return 0;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < offset)
            {
                offset = nums[i];
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            result = result + (nums[i] - offset);
        }
        
        return result;
    }

int main()
{
	vector<int> nums = {1,2,3};
	int answer = minMoves(nums);
	cout << answer << endl;

	return 0;
}
