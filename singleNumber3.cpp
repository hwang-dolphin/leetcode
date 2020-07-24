
#include <iostream>
using namespace std;

#include <vector>

vector<int> singleNumber(vector<int>& nums)
{
    // Runtime: O(N) 
    // Space: O(1)

    int x, y;
    int xSetBit = 0;
    
    int totalXor = 0;
    
    for (auto i: nums)
    {
        totalXor = totalXor ^ i;
    }
    
    // 31 bits (not 32) to avoid overloading
    // position is 0 based
    for (int i = 0; i < 32; i++)
    {
        if (((1 << i) & totalXor) != 0)
        {
            xSetBit = i;
            break;
        }
    }
    
    x = 0;
    
    for (auto i: nums)
    {
        if (i & (1 << xSetBit))
        {
            x = x ^ i;
        }
    }
    
    y = totalXor ^ x;
    
    return {x, y};
    
}


int main()
{
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> answer;

    answer = singleNumber(nums);
    
    for (auto i: answer)
    {
        cout << i << " ";
    }
    
    return 0;
}

