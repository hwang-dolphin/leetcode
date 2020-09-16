#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: Backtracking is recurssion.  Permutations is no repeat of elements allowed.
		   Formula for total permutations is N! 
		   
		   Watching the call drawing is good way to understand.
	           
	Reference:  https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/


void backtrack(vector<int> nums, vector<vector<int>> & result, int leftPtr, int numsSize)
    {
        if (leftPtr == numsSize)
        {
            result.push_back(nums);
        }
        
        for (int i = leftPtr; i < numsSize; i++)
        {
            swap(nums[leftPtr], nums[i]);
 
	    // weird, leftPtr + 1 works well but leftPtr++ does not work
            backtrack(nums, result, leftPtr + 1, numsSize);
            swap(nums[leftPtr], nums[i]);
        }
    }
  
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        
        int leftPtr = 0;
        int numsSize = nums.size();
        
        backtrack(nums, result, leftPtr, numsSize);
        
        return result;
    }

int main()
{
	vector<int> nums = {1,2,3};

	vector<vector<int>> answer = permute(nums);

	for (auto i: answer)
	{
		for (auto j: i)
		{
			cout << j << " ";
		}

		cout << endl;
	}

	return 0;
}
