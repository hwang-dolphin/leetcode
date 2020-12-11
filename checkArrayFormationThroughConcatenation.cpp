#include <iostream>
using namespace std;

#include <vector>
#include <map>

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) 
    {
        bool result = true;
        
        map<int, vector<int>> myMap;
        map<int, vector<int>>::iterator myIte;
        
        for (int i = 0; i < pieces.size(); i++)
        {
            myMap[pieces[i][0]] = pieces[i];
        }
        
        int index = 0;
        
        while (index < arr.size())
        {
            myIte = myMap.find(arr[index]);
            
            if (myIte == myMap.end())
            {
                result = false;
                break;
            }
            
            else
            {
                int oldIndex = index;
                
                for (int j = 0; j < myMap[arr[oldIndex]].size(); j++)
                {
                    if (myMap[arr[oldIndex]][j] == arr[index])
                    {
                        index++;
                    }
                    
                    else
                    {
                        result = false;
                        break;
                    }
                }
                
                if (result == false)
                {
                    break;
                }
            }
        }
        
        return result;
    }
};

int main()
{
	Solution myObj;
	vector<int> arr = {85,1,2};
	vector<vector<int>> pieces = {{85,2,1}};

	bool answer = myObj.canFormArray(arr, pieces);
	
	cout << answer << endl;

	return 0;
}

