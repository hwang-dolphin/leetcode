#include <iostream>
using namespace std;

#include <vector>

vector<int> runningSum(vector<int>& nums)
{
    int acc = 0;
    
    vector<int> result;
 
    for (int i = 0; i < nums.size(); i++)
    {
        acc += nums[i];
        result.push_back(acc);
    }

    return result;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> answer;
    
    answer = runningSum(nums);
    
    for (auto i: answer)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << __cplusplus << endl;

    
    return 0;
}
