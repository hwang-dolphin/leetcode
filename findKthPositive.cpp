/*
	Idea:  Use a counter to count initialized to 1.  Go counting and checking which one is missing.
	Use another varible to keep track of number missing.  When variable numberMissing is equal to k
	then we show stop the looping and return the counter variable.

	Runtime complexity: O(N)
	Space Complexity: O(1)
*/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int counter = 1;
        int missingIntegersFound = 0;
        
        while (missingIntegersFound < k)
        {
            if (find(arr.begin(), arr.end(), counter) == arr.end())
            {
                missingIntegersFound++;
            }
            
            if (missingIntegersFound < k)
            {
                counter++;
            }
        }
        
        return counter;
    }
};
