
#include <iostream>
using namespace std;

#include <vector>

int removeDuplicates(vector<int>& nums)
{
    int count = 1;
    
    if (nums.size() <= 2)
    {
        return (int)nums.size();
    }
    
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
        {
            count++;
            
            if (count > 2)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        
        else if (nums[i - 1] != nums[i])
        {
            count = 1;
        }
    }
    
    return (int)nums.size();
}

int main()
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    
    int answer = removeDuplicates(nums);
    
    for (auto i: nums)
    {
        cout << i << " ";
    }
    
    cout << endl;
    cout << answer << endl;

    return 0;
}


