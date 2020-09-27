#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: Brute Force.

	RunTime: O(N^3)
	Space Complexity: O(1)
*/

int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int sum = 0;
        int temp;
        
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                if ((j - i + 1) % 2 != 0)
                {
                    temp = 0;
                    
                    for (int k = i; k <= j; k++)
                    {
                        temp = temp + arr[k];
                    }
                    
                    sum = sum + temp;
                }
            }
        }
        
        return sum;
    }

int main()
{
	vector<int> arr = {1,4,2,5,3};

	int answer = sumOddLengthSubarrays(arr);

	cout << answer << endl;

	return 0;
}
