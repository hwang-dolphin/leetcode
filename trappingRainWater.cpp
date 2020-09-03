#include <iostream>
using namespace std;

#include <vector>
#include <map>


/*
	Intuition:  It is an unusual type of two pointers, or maybe three pointers thing.  The idea is to traverse 
		    elements [1, givenVector.size() - 1].  For every i between [1, givenVector.size() - 1] for both left side
		    and right side of i, find the maximum seen value so far.  For left and right, the maximum includes 
	            every elements from up to and including itself.  Get the minimum of these two maximum values and subtract 
		    the minimum to givenVector[i].  This will be the volume trapped in each element.  Add each of these volume
		    to the result.  
	
	Reference:  https://www.youtube.com/watch?v=ECbgLWIXeMo

	RunTime: O(N)
	Space Complexity: O(N)
*/


int trap(vector<int>& height)
{
    int result = 0;
    
    map<int, pair<int, int>> myMap;
    
    int maximum = INT_MIN;
    int minimum;
    
    if (height.size() < 2)
    {
        return 0;
    }
    
    maximum = height[0];
    
    for (int i = 1; i < height.size() - 1; i++)
    {
        if (height[i] >= maximum)
        {
            maximum = height[i];
        }
        
        myMap[i].first = maximum;
    }
    
    maximum = height[height.size() - 1];
    
    for (int i = height.size() - 2; i >= 1; i--)
    {
        if (height[i] >= maximum)
        {
            maximum = height[i];
        }
        
        myMap[i].second = maximum;
    }
    
    for (int i = 1; i < height.size() - 1; i++)
    {
        minimum = min(myMap[i].first, myMap[i].second);
        
        result = result + minimum - height[i];
    }
    
    return result;
}

int main()
{
    vector<int> height = {2,0,2};
    
    int answer = trap(height);

    cout << answer << endl;
    
    return 0;
}
