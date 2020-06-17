#include <iostream>
using namespace std;

#include <vector>

vector<string> generatePossibleNextMoves(string);

int main()
{
    string s = "++++";
    
    vector<string> answer = generatePossibleNextMoves(s);
    
    for (auto i: answer)
    {
        cout << i << endl;
    }
    
    return 0;
}

vector<string> generatePossibleNextMoves(string s)
{
    vector<string> result;
    
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '+' && s[i - 1] == '+')
        {
            s[i] = '-';
            s[i - 1] = '-';
            
            result.push_back(s);
            
            s[i] = '+';
            s[i - 1] = '+';
        }
    }
    
    return result;
}

