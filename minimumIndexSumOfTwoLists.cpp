#include <iostream>
using namespace std;

#include <vector>
#include <map>

/*
	Intuition: Only the elements found in both arrays that have the "least index 
		   sums" will be added to the result.

	RunTime: O(N)
	Space Complexity: O(N) 
*/


vector<string> findRestaurantV2(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> result;
        vector<string>::iterator ite;
        map<string, int> myMap;
        int j;
        int minimum = INT_MAX;

        if (list1.size() >= list2.size())
        {
            for (int i = 0; i < list1.size(); i++)
            {
                ite = find(list2.begin(), list2.end(), list1[i]);
                
                if (ite != list2.end())
                {
                    // j = distance(list2.begin(), ite);
                    j = ite - list2.begin();

                    myMap[list1[i]] = j + i;
                    
                    if (j + i < minimum)
                    {
                        minimum = j + i;
                    }
                }
            }
        }
        
        else
        {
            for (int i = 0; i < list2.size(); i++)
            {
                ite = find(list1.begin(), list1.end(), list2[i]);
                
                if (ite != list1.end())
                {
                    j = ite - list1.begin();
                    
                    myMap[list2[i]] = j + i;
                    
                    if (j + i < minimum)
                    {
                        minimum = j + i;
                    }
                }
            }
        }
        
        for (auto i: myMap)
        {
            if (i.second == minimum)
            {
                result.push_back(i.first);
            }
        }
   
        return result;
    }




vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> result;
        vector<string>::iterator ite;

        int j;
        int minimum = INT_MAX;

        if (list1.size() >= list2.size())
        {
            for (int i = 0; i < list1.size(); i++)
            {
                ite = find(list2.begin(), list2.end(), list1[i]);
                
                if (ite != list2.end())
                {
                    
                    
                    // j = distance(list2.begin(), ite);
                    j = ite - list2.begin();

                    if (j + i < minimum)
                    {
                        minimum = j + i;
                        
                        result.clear();
                        result.push_back(list1[i]);
                    }
                    
                    else if (j + i == minimum)
                    {
                        result.push_back(list1[i]);
                    }
                }
            }
        }
        
        else
        {
            for (int i = 0; i < list2.size(); i++)
            {
                ite = find(list1.begin(), list1.end(), list2[i]);
                
                if (ite != list1.end())
                {
                    j = ite - list1.begin();
                    
                    
                    if (j + i < minimum)
                    {
                        minimum = j + i;
                        
                        result.clear();
                        result.push_back(list2[i]);
                    }
                    
                    else if (j + i == minimum)
                    {
                        result.push_back(list2[i]);
                    }
                   
                }
            }
        }
    
        return result;
    }




int main()
{
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

	vector<string> answer = findRestaurant(list1, list2);

	for (auto i: answer)
	{
		cout << i << endl;
	}	

	return 0;
}
