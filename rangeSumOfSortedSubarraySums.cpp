
#include <iostream>
using namespace std;

#include <vector>

int rangeSum(vector<int>&, int, int, int);

int main()
{
    vector<int> nums = {1,2,3,4};
    int n = 4, left = 1, right = 5;
    
    int answer = rangeSum(nums, n, left, right);
    
    cout << answer << endl;
    
    return 0;
}

int rangeSum(vector<int>& nums, int n, int left, int right)
{
    int counter = 0;
    vector<int> result;
    
    long long int answer = 0;
    
    const int HUGENUMBER = 1000000007;
    
    for (int i = 0; i < nums.size(); i++)
    {
        result.push_back(nums[i]);
        counter += nums[i];
        
        if (i <= nums.size() - 2)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                counter += nums[j];
                result.push_back(counter);
            }
            
            counter = 0;
        }
    }
    
    sort(result.begin(), result.end());
    
    for (int i = left - 1; i < right; i++)
    {
        answer += result[i];
    }
    
    return (answer % HUGENUMBER);
}

