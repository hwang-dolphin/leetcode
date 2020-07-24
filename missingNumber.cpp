#include <iostream>
using namespace std;

#include <vector>

int missingNumber(vector<int>& nums) 
{
        int missingNumber = nums.size();
        
        for (int i = 0; i < nums.size(); i++)
        {
            missingNumber = missingNumber ^ (nums[i] ^ i);
        }
        
        return missingNumber;
}



int main()
{
	vector<int> nums = {0, 1, 3, 4};

	int answer = missingNumber(nums);

	cout << answer << endl;

	return 0;
}
