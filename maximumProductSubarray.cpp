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





 int maxProductV2(vector<int>& nums) 
 {
        // one pass but doing the same as V3	
	int result = 0;
        int temp = 1;
        int temp2 = 1;
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        
        int i = 0;
        int j = nums.size() - 1;
        
        while(i < nums.size() && j >= 0)
        {
            temp = temp * nums[i];
            temp2 = temp2 * nums[j];
            
            if (temp > result)
            {
                result = temp;
            }
            
            else if (temp == 0)
            {
                temp = 1;
            }
            
            if (temp2 > result)
            {
                result = temp2;
            }
            
            else if (temp2 == 0)
            {
                temp2 = 1;
            }
            
            i++;
            j--;
        }
        
        
        return result;
}


// setting max_so_far and min_so_far by taking the min or max of three numbers:
// nums[i], nums[i] * max_so_far, nums[i] * min_so_far
 int maxProduct(vector<int>& nums) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        int minProduct = nums[0];
        int maxProduct = nums[0];
        
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) 
        {
            minProduct = min_so_far * nums[i];
            maxProduct = max_so_far * nums[i];
            
            // max_so_far or min_so_far is the max or min between three numbers:
            // minProduct, maxProduct, and nums[i]
            max_so_far = max(max(minProduct, maxProduct), nums[i]);
            min_so_far = min(min(minProduct, maxProduct), nums[i]);
            
            if (max_so_far > result)
            {
                result = max_so_far;
            }
        }
        
        return result;
    }



int maxProductV3(vector<int>& nums) 
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
