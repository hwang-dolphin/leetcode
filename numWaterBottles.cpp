#include <iostream>
using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int sum = numBottles;
    
    while (numBottles >= numExchange)
    {
        sum = sum + (numBottles / numExchange);
        numBottles = (numBottles / numExchange)  + (numBottles % numExchange);
    }

    return sum;
}



int main()
{

	int numBottles = 2;
    	int numExchange = 3;
    
    	int answer = numWaterBottles(numBottles, numExchange);
    
    	cout << answer << endl;

	return 0;
}
