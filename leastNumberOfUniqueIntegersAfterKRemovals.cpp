/*
	Hai Wang
	Problem # 5454
	6-14-2020
*/


#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <queue>

int findLeastNumOfUniqueInts(vector<int>& arr, int k)
{
    map<int, int> myMap;
    map<int, int>::iterator myMapIte;
    
    // smallest number goes first
    priority_queue<int, vector<int>, greater<int>> myPq;

    for (auto i: arr)
    {
        myMap[i]++;
    }
    
    for (myMapIte = myMap.begin(); myMapIte != myMap.end(); ++myMapIte)
    {
        myPq.push(myMapIte->second);
    }
    
    while (!myPq.empty())
    {
        if (k >= myPq.top())
        {
            k = k - myPq.top();
            myPq.pop();
        }
        
        else
        {
            break;
        }
    }
   
    return (int)myPq.size();
}

int main()
{
    vector<int> arr = {4,3,1,1,3,3,2};
    int k = 3;
    
    int answer = findLeastNumOfUniqueInts(arr, k);
    
    cout << answer << endl;
    
    return 0;
}

