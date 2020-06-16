
#include<iostream>
using namespace std;

#include <map>
#include <cmath>

bool hasAllCodes(string, int);

int main()
{
    string s = "00110110";
    int k = 2;
    
    bool answer = hasAllCodes(s, k);
    
    cout << answer << endl;

    return 0;
}


bool hasAllCodes(string s, int k)
{
    // hint1:  we need to check only all sub-strings of length k
    // hint2:  the number of distinct sub-strings should be exactly 2^k
    
    
    if (s.size() < k)
    {
        return false;
    }
    
    int distinctSubStringsNeeded = pow(2.0, k);
    map <string, int> seenMap;
    
    for (int i = 0; i <= (s.size() - k); i++)
    {
        seenMap[s.substr(i, k)]++;
    }
    
    return (seenMap.size() == distinctSubStringsNeeded) ? true : false;
}
