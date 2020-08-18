#include <iostream>
using namespace std;


/*
	Intuition:  Simply use bit manipulation to find the longest distance between two bits set to 1; if there are
	no two bit set to 1 then return 0.  LeetCode problem is misleading "longest distance between two consecutive 1's"
	very misleading.  "Consecutive" word should be removed.
	
	RunTime: O(32) or O(31) for only positive integers up to 10^9
	Space: O(1)
*/



int binaryGap(int N) 
    {
        int previousSetBit = -1;
        int result = 0;
        
        for (int i = 0; i < 31; i++)
        {
            if (((1 << i) & N) > 0)
            {
                if (previousSetBit == -1)
                {
                    previousSetBit = i;
                }
                
                else if (previousSetBit != -1)
                {
                    result = max(result, i - previousSetBit);
                    previousSetBit = i;
                    
                }
            }       
        }
        
        return result;
    }


int main()
{
	int N = 5;

	int answer = binaryGap(N);

	cout << answer << endl;

	return 0;
}
