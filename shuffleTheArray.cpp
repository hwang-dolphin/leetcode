#include <iostream>
using namespace std;

#include <vector>

vector<int> shuffle(vector<int>&, int);

int main()
{
    vector<int> arr = {2,5,1,3,4,7};
    int n = 3;

    vector<int> answer = shuffle(arr, n);;
    
    for (auto i: answer)
    {
        cout << i << " ";
    }
    
    cout << endl;
    
    return 0;
}

vector<int> shuffle(vector<int>& nums, int n)
{
    vector<int> result;
    
    for (int x = 0, y = x + n; y < (2 * n); x++, y = n + x)
    {
        result.push_back(nums[x]);
        result.push_back(nums[y]);
    }
    
    return result;
}
