
#include <iostream>
using namespace std;

#include <map>
#include <vector>

void sortColors(vector<int>&);

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    
    for (auto i: nums)
    {
        cout << i << " ";
    }
    
    return 0;
}

void sortColors(vector<int>& nums)
{
    map<int, int> myMap;
    
    for (int i = 0; i < nums.size(); i++)
    {
        myMap[nums[i]]++;
    }
    
    int zeroEnd, oneEnd, twoEnd;
    
    zeroEnd = myMap[0] - 1;
    oneEnd = zeroEnd + myMap[1];
    twoEnd = oneEnd + myMap[2];
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (i >= 0 && i <= zeroEnd)
        {
            nums[i] = 0;
        }
        
        else if (i >= zeroEnd + 1 && i <= oneEnd)
        {
            nums[i] = 1;
        }
        
        else if (i >= oneEnd + 1 && i <= twoEnd)
        {
            nums[i] = 2;
        }
    }
}

