#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Start the profit equal to 0.  Always buy the lowest price stock.
		    As we traverse through the vector, keep the highest margin of profit.
		    
	RunTime: O(N)
	Space Complexity: O(1)	
*/


int maxProfit(vector<int>& prices) 
    {
        int currentMaxProfit = 0;
        int buyPrice = INT_MAX;
        
        if (prices.size() <= 1)
        {
            return currentMaxProfit;
        }
        
        buyPrice = prices[0];
        
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] <= buyPrice)
            {
                buyPrice = prices[i];
            }
            
            else if (prices[i] - buyPrice > currentMaxProfit)
            {
                currentMaxProfit = prices[i] - buyPrice;
            }
        }
        
        
        return currentMaxProfit;
    }

int main()
{
	vector<int> prices = {7,1,5,3,6,4};

	int answer = maxProfit(prices);

	cout << answer <<endl;
	return 0;
}
