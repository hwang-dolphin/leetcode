
#include <iostream>
using namespace std;

#include <vector>


/*
	Intuition:  Use modulus to circulate around the array.  Then, find out the right coordinates.
		    Use an addional array so we keep the original values through out the process.

	RunTime: O(N)
	Space Complexity: O(N)

*/

void rotate(vector<int>& nums, int k) 
    {
        vector<int> numsTemp = nums;
        
        for (int i = 0; i < nums.size(); i++)
        {
            nums[(i + k) % nums.size()] = numsTemp[i];
        }
    }

int main()
{
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 3;

	rotate(nums, k);


	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	
	cout << endl;
	
	return 0;

}
