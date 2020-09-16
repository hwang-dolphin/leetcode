
#include <iostream>
using namespace std;

#include <vector>
#include <set>

/*
	Intuition:  Find all permutations of the given array by using backTracking, and storing them in a vector of vectors.
		    From there, find the unique vectors by filtering them into a set and getting them back.

	Space Complexity: O(N)
*/


void backTrack(vector<int> nums, vector<vector<int>> & result, int left, int numsSize)
    {
        if (left == numsSize)
        {
            result.push_back(nums);
        }
        
        for (int i = left; i < numsSize; i++)
        {
            swap(nums[left], nums[i]);

	    // this 'left + 1' needs to be like this
	    // left++ will not work because maybe it is left variable needs to retain its original value 
	    // for the backtrack swap (second swap version) to work
            backTrack(nums, result, left + 1, numsSize);
            swap(nums[left], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> result;
        set<vector<int>> mySet;
        
        int left = 0;
        int numsSize = nums.size();
        
        backTrack(nums, result, left, numsSize);
        
        for (auto i: result)
        {
            mySet.insert(i);
        }
        
        result.clear();
        
        for (auto i: mySet)
        {
            result.push_back(i);
        }
        
        return result;
    }


int main()
{
	vector<int> nums = {1,1,2};
	vector<vector<int>> answer = permuteUnique(nums);
	
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
