#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	Intuition:  Very similar to the first version problem "minimum moves to equal array elements"
		    but very much harder to find the "offset".  For some reason the offset is one of 
		    the values in the given vector.  If sorted the array, it is "nums[nums.size() / 2]"

		    The result will be the sum of all elements in the array minus the offset in each iteration.

	RunTime: O(NLogN);
	Space Complexity: O(1)
*/


int minMoves2(vector<int>& nums) 
    {
        int offset;
        
        int result = 0;
        
        sort(nums.begin(), nums.end());
        
        offset = nums[nums.size() / 2];
        
        for (int i = 0; i < nums.size(); i++)
        {
            result = result + abs(nums[i] - offset);
        }
     
        return result;
    }

int main()
{
	vector<int> nums = {1,2,3};

	int answer = minMoves2(nums);

	cout << answer << endl;

	return 0;
}
