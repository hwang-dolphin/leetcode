#include <iostream>
using namespace std;

#include <vector>

int removeDuplicates(vector<int>& nums)
{
    int newPtr = 0;
    
    if (nums.size() <= 1)
    {
        return nums.size();
    }
    
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[newPtr])
        {
            newPtr++;
            
            nums[newPtr] = nums[i];
        }
    }
    
    return newPtr + 1;
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
