#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Store minimum and maximum values in their corresponding variables.  Do calculations
		    with these variables but with only one condition:  never allow them to calculate the result
		    from minimum and maximum of same array.
		    The code is divided into two major parts.  First, calculation which never allows calculation from same array.
		    The second part is the update part which puts maximum and minimum no matter if they come from same array
		    because the calculation doesn't allow calculation from same array anyways.  
		
	RunTime: O(N)
	Space Complexity: O(1)	
		
*/


int maxDistance(vector<vector<int>>& arrays) 
    {
        int minimum = arrays[0][0];
        int maximum = arrays[0][arrays[0].size() - 1];
        
        int result = INT_MIN;
        
        for (int i = 1; i < arrays.size(); i++)
        {
            // calculation part
            if (abs(maximum - arrays[i][0]) > result)
            {
                result = abs(maximum - arrays[i][0]);
            }
            
            if (abs(arrays[i][arrays[i].size() - 1] - minimum) > result)
            {
                result = abs(arrays[i][arrays[i].size() - 1] - minimum);
            }
            
            
            
            
            // update part
            if (arrays[i][0] < minimum)
            {
                minimum = arrays[i][0];
            }
            
            if (arrays[i][arrays[i].size() - 1] > maximum)
            {
                maximum = arrays[i][arrays[i].size() - 1];
            }
        }
        
        return result;
    }


int main()
{
	vector<vector<int>> arrays = {{1,2,3}, {4,5}, {1,2,3}};

	int answer = maxDistance(arrays);

	cout << answer << endl;

	return 0;
}
