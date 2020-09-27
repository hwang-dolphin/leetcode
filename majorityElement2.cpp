
#include <iostream>
using namespace std;

#include <vector>
#include <map>

/*
	Intuition: Simple traverse looking for numbers which are greater than nums.size() / 3.

	RunTime: O(N)
	Space Complexity: O(N)
*/

vector<int> majorityElement(vector<int>& nums) 
    {
        map<int, int> myMap;
        vector<int> result;
        
        for (auto i: nums)
        {
            myMap[i]++;
        }
        
        for (auto i: myMap)
        {
            if (i.second > (nums.size() / 3))
            {
                result.push_back(i.first);
            }
        }
        
        return result;
    }


int main()
{
	vector<int> nums = {1,1,1,3,3,2,2,2};
	
	vector<int> answer = majorityElement(nums);

	for (auto i: answer)
	{
		cout << i << " ";
	}

	cout << endl;

	return 0;
}
