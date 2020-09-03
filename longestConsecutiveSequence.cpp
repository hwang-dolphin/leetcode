#include <iostream>
using namespace std;

#include <vector>
#include <set>

/*
	Intuition:  Order and remove the repetitive values from nums vector by inserting
		    all values to a set.  Traverse through the set looking for the longest consecutive sequence.
		    The algorithm to look for the longest consecutive sequence uses a for loop and window of two pointers.
		    So the for loop works well with two or more elements.  For a set with 0 or only one element, 
		    code the edge cases for when nums is equal to 0 and when nums is equal to 1.

	RunTime: O(N) if inserting to a set counts as O(N)
	Space Complexity: O(N)
*/



int longestConsecutive(vector<int>& nums)
{
    set<int> numsSet;
    set<int>::iterator ite;
    
    int result = 1;
    int currValue;
    int previousValue;
    int counter = 1;
    
    // since the for loop works with window of two pointers,
    // it is a good idea to put edge cases.  we have two edge cases that
    // does not cover the for loop: when nums size is 0 or when nums size is 1
    if (nums.size() == 0)
    {
        return 0;
    }
    
    else if (nums.size() == 1)
    {
        return 1;
    }
    
    for (auto i: nums)
    {
        numsSet.insert(i);
    }

    // this loop works 100% well if the size of set is two or greater
    // since it is a two pointer algorithm, window of two pointers
    for (ite = numsSet.begin(); ite != numsSet.end(); ++ite)
    {
        if (ite == numsSet.begin())
        {
            previousValue = *ite;
            continue;
        }
        
        else
        {
            currValue = *ite;
            
            if (currValue == (previousValue + 1))
            {
                counter++;
                
                result = (counter > result) ? counter : result;
            }
            
            else
            {
                counter = 1;
            }
            
            
            previousValue = currValue;
        }
    }
    
    return result;
}


int main()
{
	vector<int> nums = {100, 4, 200, 1, 3, 2};

	int answer = longestConsecutive(nums); 	

	cout << answer << endl;

	return 0;
}
