#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  By default, if we reorder nums array to decreasing order,
		    we can traverse from the begining to the end.  As soon as the left side
	            sum is greater than the right side sum, we can break it and return the result.

	RunTime: NLog(N)
	Space Complexity: O(N)
*/



vector<int> minSubsequence(vector<int>& nums) 
    {
        vector<int> result;
        int rightSum = 0;
        int leftSum = 0;
        
        sort(nums.begin(), nums.end(), greater<int>());  
        
        for (auto i: nums)
        {
            rightSum = rightSum + i;
        }
        
        int index = 0;
        
        while (leftSum <= rightSum)
        {
            leftSum = leftSum + nums[index];
            
            result.push_back(nums[index]);
            
            rightSum = rightSum - nums[index];
            
            index++;
        }
      
        
        return result;
        
    }

int main()
{
	vector<int> nums = {4,3,10,9,8};

	vector<int> answer = minSubsequence(nums);

	for (auto i: answer)
	{	
		cout << i << " ";
	} 

	cout << endl;

	return 0;
}
