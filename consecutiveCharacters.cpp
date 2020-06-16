
/*
 Hai Wang
 1446. Consecutive Characters
 6-15-2020
*/


#include <iostream>
using namespace std;

int maxPower(string);

int main()
{
    string s = "abbcccddddeeeeedcba";
    
    int answer = maxPower(s);
    
    cout << answer << endl;
    
    return 0;
}

int maxPower(string s)
{
    int currentPower = 1;
    int maxPower = 1;
    
    if (s.size() == 1)
    {
        return maxPower;
    }
    
    else
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
            {
                currentPower++;
                
                if (currentPower > maxPower)
                {
                    maxPower = currentPower;
                }
            }
            
            else
            {
                currentPower = 1;
            }
        }
    }
    
    return maxPower;
}
 

