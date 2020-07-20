#include <iostream>
using namespace std;

string addBinary(string a, string b)
{
    string answer;
    
    string first = a;
    string second = b;
    char carryOn = '0';
    char bitResult;

    int bitSizeDesired = max(a.size(), b.size()) + 1;
    int neededBits;
    
    neededBits = bitSizeDesired - first.size();
    
    for (int i = 0; i < neededBits; i++)
    {
        first.insert(0, "0");
    }
    
    neededBits = bitSizeDesired - second.size();
    
    for (int i = 0; i < neededBits; i++)
    {
        second.insert(0, "0");
    }

    for (int i = first.size() - 1; i >= 0; i--)
    {
        if (carryOn == '0' && first[i] == '0' && second[i] == '0')
        {
            bitResult = '0';
            carryOn = '0';
        }
        
        else if (carryOn == '0' && first[i] == '0' && second[i] == '1')
        {
            bitResult = '1';
            carryOn = '0';
        }
        
        else if (carryOn == '0' && first[i] == '1' && second[i] == '0')
        {
            bitResult = '1';
            carryOn = '0';
        }
        
        else if (carryOn == '0' && first[i] == '1' && second[i] == '1')
        {
            bitResult = '0';
            carryOn = '1';
        }
        
        else if (carryOn == '1' && first[i] == '0' && second[i] == '0')
        {
            bitResult = '1';
            carryOn = '0';
        }
        
        else if (carryOn == '1' && first[i] == '0' && second[i] == '1')
        {
            bitResult = '0';
            carryOn = '1';
        }
        
        else if (carryOn == '1' && first[i] == '1' && second[i] == '0')
        {
            bitResult = '0';
            carryOn = '1';
        }
        
        else if (carryOn == '1' && first[i] == '1' && second[i] == '1')
        {
            bitResult = '1';
            carryOn = '1';
        }
        
        
        answer.insert(0, to_string(bitResult - 48));
    }
    
    if (answer[0] == '0' && answer.size() != 1)
    {
        answer.erase(0, 1);
    }
    
    return answer;
}

int main()
{
    string a = "1010";
    string b = "1011";
    
    string result = addBinary(a, b);
    
    cout << result << endl;
    
    return 0;
}

