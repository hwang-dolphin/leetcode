#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  LeetCode solution two pointer sliding window is bit confusing a very new concept.
		    This "two pointer sliding window behaves differently from other sliding winding for string or 
		    arrays.  And this problem does not use Hash Map sum like other similar array problem.

		    *** needs to review this solution ****		    


	RunTime: O(N)
	Space Complexity: O(1)
*/

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int result = 0;
    int productSum = 1;
    int left = 0;
    
    if (k <= 1)
    {
        return 0;
    }
    
    for (int r = 0; r < nums.size(); r++)
    {
        productSum = productSum * nums[r];
        
        while (productSum >= k)
        {
            productSum = productSum / nums[left];
            left++;
        }
        
        result = result + (r - left + 1);
    }

    return result;
}


int main()
{
	 
    int k = 100;
    vector<int> nums = {10, 5, 2, 6};
    
    int answer = numSubarrayProductLessThanK(nums, k);
    
    cout << answer << endl;
    
    return 0;
}
