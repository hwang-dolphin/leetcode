#include <iostream>
using namespace std;

#include <vector>
#include <map>

/*
	Intuition:  Make an map of cumulative sums and how many times seen it as values
		    Since we hava cumulative sum, and S then the formula is "sum - S" 
	            we check in map how many times we have seen "sum - S" which end up to be how
		    many times we seen the subarray "S".
		    Got this idea from leetcode.

	RunTime: O(n);
	Space complexity: O(n);
*/



int numSubarraysWithSum(vector<int>& A, int S) 
    {
        map<int, int> myMap;
        myMap[0]++;
        
        int result = 0;
        int sum = 0;
        
        for (int i = 0; i < A.size(); i++)
        {
            sum = sum + A[i];
            
            if (myMap.find(sum - S) != myMap.end())
            {
                result = result + myMap[sum - S];
            }
            
            myMap[sum]++;
        }
        
        return result;
    }

int main()
{
	vector<int> A = {1,0,1,0,1};
	int S = 2;

	int answer = numSubarraysWithSum(A, S);

	cout << answer << endl;

	return 0;
}
