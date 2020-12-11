#include <iostream>
using namespace std;

#include <vector>
#include <map>

/*
Intuition:  Take advantage of the fact that the arrays in mat do not have duplicates.
            This way we can create a dictionary of number frequencies.  We should search
            in the dictionary of frequencies for the smallest key which have a frequency
            equal to the size of "mat" array.
   
RunTime: O(NM), N = number of elements in mat, M = number of elements in N
Space Complexity: O(K), K = number of unique elements
*/


class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) 
    {
        int result = -1;
        
        map<int, int> myMap;
        
        for (auto i: mat)
        {
            for (auto j: i)
            {
                myMap[j]++;
            }
        }
        
        for (auto i: myMap)
        {
            if (i.second == mat.size())
            {
                result = i.first;
                break;
            }
        }
        
        return result;
    }
};


int main()
{
	vector<vector<int>> mat = {{1,2,3,4,5},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};

	Solution myObj;
	int answer = myObj.smallestCommonElement(mat);

	cout << answer << endl;

	return 0;
}
