/*
	Intuition: make a map of arr2 keys and values, the values should be ints i element value.
		   then create a customSort to sort only a vector of elemnts that are in arr2.

		   the map needs to be outside of the class to work so the customSort can use it.
		   the 'relativeSortArray' must contain a line of "myMap.clear();" in order to pass
		   through all Leetcode tests successfully.

	RunTime: O(NLog(N))
	Space Complexity: O(N)

*/


map<int, int> myMap;

bool customSort(int a, int b)
{
    bool answer;
    
    if (myMap[a] <= myMap[b])
    {
        answer = true;
    }
    
    else if (myMap[a] > myMap[b])
    {
        answer = false;
    }
   
    return answer;
}

class Solution 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        // why we need this?
        // non local
        myMap.clear();
        
        vector<int> result;
        vector<int> dontAppear;
        
        for (int i = 0; i < arr2.size(); i++)
        {
            myMap[arr2[i]] = i;
        }
        
        for (int i = 0; i < arr1.size(); i++)
        {
            if (myMap.find(arr1[i]) != myMap.end())
            {
                result.push_back(arr1[i]);
            }
            
            else
            {
                dontAppear.push_back(arr1[i]);
            }
        }
        
        sort(result.begin(), result.end(), customSort);
        sort(dontAppear.begin(), dontAppear.end());
        
        for (int i = 0; i < dontAppear.size(); i++)
        {
            result.push_back(dontAppear[i]);
        }
        
        return result;
    }
};
