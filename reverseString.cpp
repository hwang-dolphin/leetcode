
/*
	Hai Wang
	Reverse String
	6-20-2020
*/

#include <iostream>
using namespace std;

#include <vector>

void reverseString(vector<char>&);

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    reverseString(s);
    
    for (auto i: s)
    {
        cout << i << " ";
    }
    
    return 0;
}

void reverseString(vector<char>& s)
{
    int leftPtr = 0;
    int rightPtr = (int)s.size() - 1;
    char temp;
    
    while (leftPtr < rightPtr)
    {
        temp = s[leftPtr];
        s[leftPtr]= s[rightPtr];
        s[rightPtr] = temp;
        leftPtr++;
        rightPtr--;
    }
}
