#include <iostream>
using namespace std;

int minFlips(string target)
{
    // left to right strategy
    // problem is: if switch element '3' all the bulbs from '3' to 'n - 1' will change state (on to off or off to on)
    char state = '0';
    int result = 0;
    
    for (auto i: target)
    {
        if (i != state)
        {
            state = i;
            result++;
        }
    }
    
    return result;
}

int main()
{    
    string s = "10111";
    int answer = minFlips(s);
    
    cout << answer << endl;
    
    return 0;
}

