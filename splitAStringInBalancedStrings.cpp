#include <iostream>
using namespace std;

int balancedStringSplit(string s) 
{
 	int balance = 0;
        int counter = 0;
        
        for (auto i: s)
        {
            if (i == 'L')
            {
                balance--;
            }
            
            else if (i == 'R')
            {
                balance++;
            }

            if (balance == 0)
            {
                counter++;
            }
        }
        
        return counter;
}


int main()
{
	string s = "RLRRLLRLRL";

	int answer = balancedStringSplit(s);

	cout << answer << endl;

	return 0;

}
