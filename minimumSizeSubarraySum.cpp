#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Simple two pointers window.  Right pointer moves ahead when current window is a "bad window".
		    Left pointer moves ahead when current window is a "good window".  

		    Good window is when sum >= s.
		    Bad Window is when sum < s.

		    Since we are trying to find the minimum length then the left pointer must move
		    all to the end of the array.

	RunTime: O(N)
	Space Complexity: O(1)
*/

 int minSubArrayLen(int s, vector<int>& nums) 
    {
        int result = INT_MAX;
        
        int left = 0;
        int sum = 0;
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        else if (nums.size() == 1 && nums[0] >= s)
        {
            return 1;
        }
        
        else if (nums.size() == 1 && nums[0] < s)
        {
            return 0;
        }
        
        for (int right = 0; right < nums.size(); right++)
        {
            sum = sum + nums[right];
            
            if (sum >= s)
            {
                while (sum >= s)
                {
                    if (right - left + 1 < result)
                    {
                        result = right - left + 1;
                    }
                    
                    sum = sum - nums[left];
                    left++;
                }
            }
        }
        
        for (int l = left; l < nums.size(); l++)
        {
            if (sum >= s)
            {
                if (nums.size() - 1 - l + 1 < result)
                {
                    result = nums.size() - 1 - l + 1;
                }
            }
            
            sum = sum - nums[l];
        }
        
        return (result == INT_MAX) ? 0 : result;
    }

int main()
{
	int s = 7;
	vector<int> nums = {2,3,1,2,4,3};

	int answer = minSubArrayLen(s, nums);

	cout << answer << endl;

	return 0;
}
