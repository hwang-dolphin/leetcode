#include <iostream>
using namespace std;

#include <vector>
#include <map>


/*
	Intuition:  It builds from the concept of "finding total subarray sum equals k" but needs
		    to modify the result to show only the maximum subarray.

		    Use O(N) one pass prefix-sum type (not two pointer array).  A map of key and a pair of
		    values how many times it been seen and the size of the subarray.

		    Play with the math equation and you will be able to come up with a formula to measure 
		    the unknown x subrray size with the values of current subarray size and seen subrray size.

		    Make sure to update the value of result every time find an x value so the result holds
		    the maximum subarray size.


	RunTime: O(N)
	Space Complexity: O(1) 

*/



int maxSubArrayLen(vector<int>& nums, int k) 
    {
        int result = 0;
        int sum = 0;
        
        int subarraySize;
        int seen;
        
        map<int, pair<int, int>> myMap;
        myMap.insert(make_pair(0, make_pair(1, 0)));

        if (nums.size() == 0)
        {
            return 0;
        }
        
        else if (nums.size() == 1 && nums[0] == k)
        {
            return 1;
        }
        
        else if (nums.size() == 1 && nums[0] != k)
        {
            return 0;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            
            if (myMap.find(sum - k) != myMap.end())
            {
                subarraySize = (i + 1) - myMap[sum - k].second;
                
                if (subarraySize > result)
                {
                    result = subarraySize;
                }
            }
            
            
            if (myMap.find(sum) != myMap.end())
            {
                seen = myMap[sum].first;
                seen++;
                
                myMap.insert(make_pair(sum, make_pair(seen, i + 1)));
            }
            
            else if (myMap.find(sum) == myMap.end())
            {
                myMap.insert(make_pair(sum, make_pair(1, i + 1)));
            }
        }
      
        
        return result;
    }

int main()
{
	vector<int> nums = {-2, -1, 2, 1};
	int k = 1;

	int answer = maxSubArrayLen(nums, k);
	cout << answer << endl;

	return 0;

}
