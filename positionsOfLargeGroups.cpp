#include <iostream>
using namespace std;

#include <vector>
#include <map>

	/*
	Intuition:  two pointers, left and right.  Use a window of two elements comparing and setting leftPtr and rightPtr.

	RunTime: O(N)
	Space Complexity: O(N)
	*/


	bool customSort(vector<int> a, vector<int> b)
	{
    		return (a[0] < b[0]) ? true : false;
	}


    vector<vector<int>> largeGroupPositionsV2(string S) 
    {
        vector<vector<int>> result;
        
        map<int, pair<int, int>> myMap;
        
        int left = 0;
        int right = 0;
        
        if (S.size() == 1)
        {
            return result;
        }
        
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i - 1] != S[i])
            {
                left = i;
            }
            
            else 
            {
                right = i;
            }
            
            if (S[i - 1] == S[i] && right - left + 1 >= 3)
            {
                if (myMap.find(left) == myMap.end())
                {
                    myMap.insert(make_pair(left, make_pair(left, right)));
                }
                
                else
                {
                    myMap.erase(left);
                    myMap.insert(make_pair(left, make_pair(left, right)));
                }
            }
        }
        
        for (auto i: myMap)
        {
            result.push_back({i.second.first, i.second.second});
        }
        
        sort(result.begin(), result.end(), customSort);
        
        return result;
    }


    vector<vector<int>> largeGroupPositions(string S) 
    {
        vector<vector<int>> result;
      
        int left = 0;
        int right = 0;
        
        if (S.size() == 1)
        {
            return result;
        }
        
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i - 1] != S[i])
            {
                if (right - left + 1 >= 3)
                {
                    result.push_back({left, right});
                }
        
                left = i;
            }
            
            else 
            {
                right = i;
            }
            
            if (i == S.size() - 1)
            {
                if (S[i - 1] == S[i] && right - left + 1 >= 3)
                {
                    result.push_back({left, right});
                }
            }
        }
        
        return result;
    }

    int main()
    {
	string S = "abcdddeeeeaabbbcd";

	vector<vector<int>> answer = largeGroupPositions(S);

	for (auto i: answer)
	{
		cout << i[0] << " " << i[1] << endl;
	}	

	return 0;
    }
