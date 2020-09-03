#include <iostream>
using namespace std;

#include <map>
#include <vector>

/*
	Intuition: this problem is very similar to problem "Subarray Sum Equals K".
		   If we convert all even numbers in nums to 0 and all odd numbers to 1.
		   We can copy and paste the code of "Subarray Sum Equals K", it should work.

	RunTime: O(N)
	Space Complexity: O(N)		   
*/


int numberOfSubarrays(vector<int>& nums, int k)
{
    int result = 0;
    int sum = 0;

    
    map<int, int> myMap;
    myMap[0]++;
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            nums[i] = 0;
        }
        
        else
        {
            nums[i] = 1;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        
        if (myMap.find(sum - k) != myMap.end())
        {
            result = result + myMap[sum - k];
        }
        
        myMap[sum]++;
    }
    
    return result;
}


int main()
{
    int k = 3;
    vector<int> nums = {1,1,2,1,1};
    
    int answer = numberOfSubarrays(nums, k);
    
    cout << answer << endl;
    
    return 0;
}
