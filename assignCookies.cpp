#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	Intuition: Sort both arrays.  Traverse through the cookies array
			   trying to get rid of cookies that are smaller than childrens'
			   appetite.  When we find a cookie that satisfy a child then we increase counter
			   and move to another kid.  If we have finished all children before finishing
			   all cookies, we simply break and end the counting.

	RunTime: O(N Log N)
	Space Complexity: O(1)
*/



class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int counter = 0;
        int childPtr = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < g[childPtr])
            {
                continue;
            }
            
            else if (s[i] >= g[childPtr])
            {
                counter++;
                childPtr++;
                
                if (childPtr >= g.size())
                {
                    break;
                }
            }
        }
        
        return counter;
    }
};

int main()
{
	vector<int> g = {1,2};
	vector<int> s = {1,2,3};

	Solution myObj = Solution();
	
	int answer = myObj.findContentChildren(g, s);

	cout << answer << endl;

	return 0;
}
