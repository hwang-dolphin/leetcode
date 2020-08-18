#include <iostream>
using namespace std;

#include <vector>


/*

	Intuition:  Not much thinking here just using "naive approach".  It is bit like writing a "hash table"
		    trying to avoid index going out of bounds and returning to the beginning of the array using modulus.
		    And Book keeping the variables using debugging.


 
	Space Complexity: O(N), N refering to numberOfPeople

*/

vector<int> distributeCandies(int candies, int num_people) 
    { 
        vector<int> result(num_people, 0);
        
        int index = 0;
        int numberOfCandiesToGive = 1;
            
        while(candies > 0)
        {
            if (candies >= numberOfCandiesToGive)
            {
                result[index % num_people] = result[index % num_people] + numberOfCandiesToGive;
            }
            
            else if (candies < numberOfCandiesToGive)
            {
                result[index % num_people] = result[index % num_people] + candies;
            }
           
            index++;
            
            candies = candies - numberOfCandiesToGive;
            numberOfCandiesToGive++;
        }
        
        return result;
        
    }


int main()
{
	int candies = 10;
	int num_people = 3;

	vector<int> answer = distributeCandies(candies, num_people);

	for (auto i: answer)
	{
		cout << i << " ";
	}

	return 0;
}
