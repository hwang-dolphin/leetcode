#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Brute Force to get all subarrays but excluding subarrays with length equal to 1.
		    Check if each subarray is divisable by k in other words (sum % k).  Before checking 
		    if they are divisible by k, use a condition filter test case for when k = 0.

	RunTime: O(N^2)
	Space complexity: O(1)

	Notes:  need to find better runtime
*/


bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int sum = 0;
        bool answer = false;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (i == j)
                {
                    sum = nums[i];
                    continue;
                }
                
                else
                {
                    sum = sum + nums[j];
                }
                
                // filter condition cases for when k == 0
                if (k == 0)
                {
                    if (sum == 0)
                    {
                        answer = true;
                        break;
                    }
                    
                    else if (sum > 0)
                    {
                        continue;
                    }
                }
                // filter condition cases for when k == 0
                
                
                if ((sum % k) == 0)
                {
                    answer = true;
                    break;
                }
            }
            
            if (answer)
            {
                break;
            }
        }
        
        return answer;
    }


int main()
{
	vector<int> nums = {23,2,4,6,7};
	int k = 6;

	int answer = checkSubarraySum(nums, k);

	cout << answer << endl;

	return 0;

}
