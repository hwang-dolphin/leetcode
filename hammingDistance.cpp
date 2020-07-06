#include <iostream>
using namespace std;

int hammingDistance(int x, int y) 
{
        int result = x ^ y;
        unsigned int mask = 1;
        
        int counterResult = 0;
    
        
        for (int i = 0; i < 32; i++)
        {
            if ((result & mask) != 0)
            {
                counterResult++;
            }
            
            mask = mask << 1;
        }
        
        return counterResult;
}


int main()
{
	int x = 1;
	int y = 4;

	int answer;

	answer = hammingDistance(x, y);	

	cout << answer << endl;

	return 0;
}
