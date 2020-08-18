#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Simple brute force.  Traverse through all subarrays, if "nums[i]" (left most) happen
		    to be higher than "nums[j]" simply break out of inner j loop because the rule says
                    "The leftmost element of the subarray is not larger than other elements in the subarray".

	RunTime: O(n^2)
	Space Complexity: O(1)

*/



int validSubarrays(vector<int>& nums) 
    {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] <= nums[j])
                {
                    count++;
                }
                
                else if (nums[i] > nums[j])
                {
                    break;
                }
            }
        }
        
        return count;
    }


int main()
{
	vector<int> nums = {1,4,2,5,3};

	int answer =  validSubarrays(nums);

	cout << answer << endl;	


	return 0;
}
