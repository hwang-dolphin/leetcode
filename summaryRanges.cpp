#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: Sliding window and checking for good window vs bad window updating the pointers minElement and maxElement.
	RunTime: O(N)
	Space Complexity: O(N)
*/



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> result;
        
        int minimumPtr, maximumPtr;
        
        if (nums.size() == 0)
        {
            return result;
        }
        
        else if (nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        
        minimumPtr = 0;
        maximumPtr = 0;
        
        for (int i = 1; i < nums.size(); i++)
        {
			// unsigned int to take care of overflow
            if ((unsigned int)nums[i] - nums[i - 1] == 1)
            {
                maximumPtr = i;
                
                if (i == nums.size() - 1)
                {
                    result.push_back(to_string(nums[minimumPtr]) + "->" + to_string(nums[maximumPtr]));
                }
            }
            
            else
            {
                if (minimumPtr == maximumPtr)
                {
                    result.push_back(to_string(nums[minimumPtr]));
                }
                
                else if (minimumPtr != maximumPtr)
                {
                    result.push_back(to_string(nums[minimumPtr]) + "->" + to_string(nums[maximumPtr]));
                }
                
                minimumPtr = i;
                maximumPtr = i;
                
                if (i == nums.size() - 1)
                {
                    result.push_back(to_string(nums[minimumPtr]));
                }
            }
        }
              
        return result;
    }
};

int main()
{
	vector<int> nums = {-2147483648,-2147483647,2147483647};

	Solution myObj;
	vector<string> answer = myObj.summaryRanges(nums);

	for (auto i: answer)
	{
		cout << i << endl;
	}

	return 0;
}

