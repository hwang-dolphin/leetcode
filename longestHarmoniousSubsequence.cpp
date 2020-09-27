#include <iostream>
using namespace std;

#include <vector>
#include <map>

/*
	Intuition:  Since a "subsequence" can have its elements deleted in the question, 
		    then we can use the technique of "seen how many times".  Add the current
		    element to the "seen" table and play with the calculations if have seen 
		    sucessor of current element and precessor of current element.
		    Current element - 1 and current element + 1.  Make sure the max and min value
		    is equal to one.  Use logic "00", "01", "10", "11" table.


	Runtime: O(N)
	Space Complexity: O(N)
*/


   int findLHS(vector<int>& nums) 
    {
        map<int, int> seenMap;
        int longest = 0;
        
        int temp;
        
        for (int i = 0; i < nums.size(); i++)
        {
            seenMap[nums[i]]++;
      
            if (seenMap.find(nums[i] - 1) == seenMap.end() && 
                seenMap.find(nums[i] + 1) == seenMap.end())
            {
                temp = 0;
            }
            
            else if (seenMap.find(nums[i] - 1) != seenMap.end() && 
                     seenMap.find(nums[i] + 1) == seenMap.end())
            {
                temp = seenMap[nums[i]] + seenMap[nums[i] - 1];
            }
            
            else if (seenMap.find(nums[i] - 1) == seenMap.end() && 
                     seenMap.find(nums[i] + 1) != seenMap.end())
            {
                temp = seenMap[nums[i]] + seenMap[nums[i] + 1];
            }
            
            else if (seenMap.find(nums[i] - 1) != seenMap.end() && 
                     seenMap.find(nums[i] + 1) != seenMap.end())
            {
                temp = (seenMap[nums[i]] + seenMap[nums[i] - 1] >=                                       seenMap[nums[i]] + seenMap[nums[i] + 1]) ?                                       seenMap[nums[i]] + seenMap[nums[i] - 1] : 
                        seenMap[nums[i]] + seenMap[nums[i] + 1];
            }
            
            if (temp > longest)
            {
                longest = temp;
            }
        }
        
        return longest;
    }

int main()
{
	vector<int> nums = {-3,-1,-1,-1,-3,-2};

	int answer = findLHS(nums);

	cout << answer << endl;	

	return 0;

}
