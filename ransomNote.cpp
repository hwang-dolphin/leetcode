
#include <iostream>
using namespace std;

#include <map>

bool canConstruct(string, string);

int main()
{
    string ransomNote = "a";
    string magazine = "b";
    bool answer = canConstruct(ransomNote, magazine);
    
    cout << answer << endl;
    
    return 0;
}

bool canConstruct(string ransomNote, string magazine)
{
    bool result = true;
    
    map<char, int> magazineMap;
    map<char, int>::iterator magazineMapIte;
    
    for (int i = 0; i < magazine.size(); i++)
    {
        magazineMap[magazine[i]]++;
    }
    
    for (int i = 0; i < ransomNote.size(); i++)
    {
        magazineMapIte = magazineMap.find(ransomNote[i]);
        
        if (magazineMapIte == magazineMap.end() ||
            magazineMap[magazineMapIte->first] == 0)
        {
            result = false;
            break;
        }
        
        else
        {
            magazineMap[magazineMapIte->first]--;
        }
    }
    
    return result;
}


