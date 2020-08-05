#include <iostream>
using namespace std;

#include <vector>

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
    vector<int> prefixSum;
    vector<int> result;
    
    prefixSum.push_back(arr[0]);
    
    for (int i = 1; i < arr.size(); i++)
    {
        prefixSum.push_back(prefixSum[i - 1] ^ arr[i]);
    }
    
    
    for (auto i: queries)
    {
        if (i[0] == 0)
        {
            result.push_back(prefixSum[i[1]]);
        }
        
        else
        {
            // for some reason, the queries that work in the prefixSum
            // is done:  for [2,3], writing the code for [1,3]
            // don't know why yet
            result.push_back(prefixSum[i[0] - 1] ^ prefixSum[i[1]]);
        }
    }
    
    return result;
}


int main()
{
    vector<int> arr = {4,8,2,10};
    vector<vector<int>> queries = {{2,3},{1,3},{0,0},{0,3}};
    
    vector<int> answer = xorQueries(arr, queries);
    
    for (auto i: answer)
    {
        cout << i << " ";
    }
    
    return 0;
}
