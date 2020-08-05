#include <iostream>
using namespace std;

#include <vector>

int getWinner(vector<int>& arr, int k)
{
    /*
	The idea is similar to sport event.  For example, the current champion sits in arr[0] 
	and a for loop traverses from index i = 1 until i = arr.size() (all other integers as challengers)
	each iteration sets up a match arr[0] (champion) vs arr[i] (challenger) 
        if champion wins then currentWin++ otherwise if challenger wins then challenger becomes champion
	and currentWin = 1.

	if currentWin is equal to k, then return champion as winner.

	programming: 
	1) if k >= arr.size() - 1
		return the biggestInteger in the array
	2) one pass for loop to for matching champion vs challenger
		currentChampion who wins is equal k then return currentChampion

    */

    int biggestInteger = INT_MIN;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > biggestInteger)
        {
            biggestInteger = arr[i];
        }
    }
    
    if (k >= arr.size() - 1)
    {
        return biggestInteger;
    }
    
    int currentWinner = arr[0];
    int currentWin = 0;
    
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > currentWinner)
        {
            currentWinner = arr[i];
            currentWin = 1;
        }
        
        else if (arr[i] < currentWinner)
        {
            currentWin++;
        }
        
        if (currentWin == k)
        {
            break;
        }
    }
    
    return currentWinner;
}

int main()
{
    int k = 2;
    vector<int> arr = {2,1,3,5,4,6,7};
    int answer;
    answer = getWinner(arr, k);
    
    cout << answer << endl;
    
    return 0;
}

