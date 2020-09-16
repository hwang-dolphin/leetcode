#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>

/*
	Simple finding frequency problem using map or one traversal O(N)
	RunTime: O(N)
	Space Complexity: O(1) 
*/


int findSpecialIntegerV2(vector<int>& arr) 
    {
        unordered_map<int, int> myMap;
        int result;
        
        for (auto i: arr)
        {
            myMap[i]++;
        }
        
        for (auto i: myMap)
        {
            if (i.second > arr.size() / 4)
            {
                result = i.first;
                break;
            }
        }
        
        return result;
    }


int findSpecialInteger(vector<int>& arr) 
    {
        int counter = 1;
        int result;
        
        if (arr.size() <= 2)
        {
            return arr[0];
        }
        
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] == arr[i])
            {
                result = arr[i];
                counter++;
                
                if (counter > arr.size() / 4)
                {
                    break;
                }
            }
            
            else if (arr[i - 1] != arr[i])
            {
                counter = 1;
            }
        }
        
        return result;
    }


int main()
{
	vector<int> arr = {1,2,2,6,6,6,6,7,10};
	int answer = findSpecialInteger(arr);

	cout << answer << endl;

	return 0;
}
