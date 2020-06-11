/*
Hai Wang
Leetcode - Destination City
*/

include <iostream>
using namespace std;

#include <vector>
#include <map>

string destCity(vector<vector<string>>& paths)
{
    // graph represented by a map
    string result;
    
    map<string, bool> myMap;
    map<string, bool>::iterator myMapIte;
    
    for (auto i: paths)
    {
        myMap[i[0]] = true;
        
        myMapIte = myMap.find(i[1]);
        
        if (myMapIte == myMap.end())
        {
            myMap[i[1]] = false;
        }
    
        else
        {
            myMap[i[1]] = true;
        }
    }
    
    for (auto i: myMap)
    {
        if (i.second == false)
        {
            result = i.first;
            break;
        }
    }
    
    return result;
}


int main()
{
    vector<vector<string>>  givenStr = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    
    string myResult = destCity(givenStr);
   
    cout << myResult << endl;

    return 0;
}
