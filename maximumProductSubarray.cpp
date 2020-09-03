#include <iostream>
using namespace std;

#include <vector> 

/*
	Intuition:  two way pass, one from left to right and another from right to left.
		    For some reason, this way will take care of wrong test cases related to negative values.

		    Simple traverse through the array looking for largest product sum.  But be careful
		    with zeros, temp variable should not be zero otherwise every next pre-sum will equal to zero.
		    As soon as temp is zero, reset it to 1 for next calculations.

		    The second traversal pass will take care of negative values of any bugs from first pass.

		    **** Needs better algorithm, although it is very fast and space complexity is minimum  ****


	RunTime: O(N)
	Space Complexity: O(1)
*/



int maxProduct(vector<int>& nums) 
    {
        int result = 0;
        int temp = 1;
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        
        for (auto i: nums)
        {
            temp = temp * i;
            
            if (temp > result)
            {
                result = temp;
            }
            
            if (temp == 0)
            {
                temp = 1;
            }
        }
        
        temp = 1;
        
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            temp = temp * nums[i];
            
            if (temp > result)
            {
                result = temp;
            }
            
            if (temp == 0)
            {
                temp = 1;
            }
        }
        
        return result;
    }


int main()
{
	vector<int> nums = {-1,0,-3,-4,-2,-5,-100,0,-1,-2,-8,0};

	int answer = maxProduct(nums);

	cout << answer << endl;
	return 0;
}
