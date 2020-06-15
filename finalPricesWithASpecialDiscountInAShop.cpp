#include <iostream>
using namespace std;

#include <vector>

vector<int> finalPrices(vector<int>& prices)
{
    vector<int> result;
    
    for (int i = 0; i < prices.size() - 1; i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] <= prices[i])
            {
                result.push_back(prices[i] - prices[j]);
                break;
            }
            
            if (j == prices.size() - 1)
            {
                result.push_back(prices[i]);
            }
        }
    }
    
    result.push_back(prices[prices.size() - 1]);
    
    return result;
}

int main()
{
    vector<int> arr = {8,4,6,2,3};

    vector<int> answer = finalPrices(arr);
    
    for (auto i: answer)
    {
        cout << i << " ";
    }
    
    cout << endl;
    
    return 0;
}

