
#include <iostream>
using namespace std;

#include <vector>
#include <climits>

/*
Intuition: Brute force to loop and find every possible combination of 3 elements.  Use a variable resultTemp
           to store the current closest value to the target (use another variable to store the sum of these 3
	   elements).

RunTime complexity: O(n^3)
Space Complexity: O(1)
*/

int threeSumClosest(vector<int>& nums, int target) 
    {
        int resultTemp = INT_MAX;
        int result;
        
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (abs((nums[i] + nums[j] + nums[k]) - target) < resultTemp)
                    {
                        resultTemp = abs((nums[i] + nums[j] + nums[k]) - target);
                        result = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        
        return result;
    }


int main()
{
	vector<int> nums = {-1,2,1,-4};	
	int target = 1;

	int answer = threeSumClosest(nums, target);

	cout << answer << endl;

	return 0;
}
