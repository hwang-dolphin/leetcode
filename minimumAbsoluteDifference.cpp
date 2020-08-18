#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	Intuition:  Start by sorting the given array to reduce the run time to NLOG(N)
		    User "two pointers" window to find the "minimumAbsolute".
		    Traverse through the sorted array using "two pointers window" to find pairs
		    with absoluteMinimum Difference; when found, simply add they into the result.

	RunTime complexity: OLOG(N)
*/



vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        int minimumAbsolute = INT_MAX;
        
        vector<vector<int>> result;
        vector<int> temp;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) < minimumAbsolute)
            {
                minimumAbsolute = abs(arr[i] - arr[i - 1]);
            }
        }
        
        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) == minimumAbsolute)
            {
                temp.push_back(arr[i - 1]);
                temp.push_back(arr[i]);
                
                result.push_back(temp);
                temp.clear();
            }
        }
        
        return result;
    }


int main()
{
	vector<int> arr = {4,2,1,3};
	
	vector<vector<int>> answer = minimumAbsDifference(arr);

	for (auto i: answer)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}	

		cout << endl;
	} 

	return 0;

}
