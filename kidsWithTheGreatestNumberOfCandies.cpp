#include <iostream>
using namespace std;

#include <vector>

vector<bool> kidsWithCandies(vector<int>&, int);

int main()
{
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    
    vector<bool> answer = kidsWithCandies(candies, extraCandies);
    
    for (auto i: answer)
    {
        cout << i << " ";
    }
    
    return 0;
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    vector<bool> result;
    int greatestNumber = 0;
    
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] > greatestNumber)
        {
            greatestNumber = candies[i];
        }
    }
    
    for (int i = 0; i < candies.size(); i++)
    {
        ((candies[i] + extraCandies) >= greatestNumber) ? result.push_back(true) : result.push_back(false);
        
    }
    
    return result;
}


