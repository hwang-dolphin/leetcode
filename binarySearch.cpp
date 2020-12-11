#include <iostream>
using namespace std;

#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        
        int result = -1;
        
        while (left <= right)
        {
            middle = ((right - left) / 2) + left;
            
            if (nums[middle] == target)
            {
                result = middle;
                break;
            }
            
            else if (target > nums[middle])
            {
                left = middle + 1;
            }
            
            else if (target < nums[middle])
            {
                right = middle - 1;
            }
            
        }
        
        return result;
    }
};

int main()
{
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;

	Solution myObject;

	int answer = myObject.search(nums, target);

	cout << answer << endl;		

	return 0;
}
