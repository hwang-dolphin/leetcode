#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: Simple two-element sliding window traversal comparing 
			   the results according to the rules.

	RunTime: O(N)
	Space Complexity: O(1)
*/



class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        char result = keysPressed[0];
        int longest = releaseTimes[0];
        
        for (int i = 1; i < releaseTimes.size(); i++)
        {
            if ((releaseTimes[i] - releaseTimes[i - 1]) > longest)
            {
                longest = releaseTimes[i] - releaseTimes[i - 1];
                result = keysPressed[i];
            }
            
            else if ((releaseTimes[i] - releaseTimes[i - 1]) == longest)
            {
                result = (result > keysPressed[i]) ? result : keysPressed[i];
            }
        }
        
        return result;
    }
};

int main()
{
	vector<int> releaseTimes = {9,29,49,50};
	string keysPressed = "cbcd";

	Solution myObj;
	char answer = myObj.slowestKey(releaseTimes, keysPressed);

	cout << answer << endl;

	return 0;
}
