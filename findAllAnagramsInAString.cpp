/*
Hai Wang
438. Find All Anagrams in a String

Sliding Window with two maps
*/


#include <iostream>
using namespace std;

#include <vector>
#include <map>

vector<int> findAnagrams(string, string);

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    

    vector<int> answer = findAnagrams(s, p);
    
    for(auto i: answer)
    {
        cout << i << " ";
    }
    
    return 0;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> result;

    map<char, int> pMap;
    map<char, int> sTempMap;
    map<char, int>::iterator sTempMapIte;
    
    if (s.size() < p.size())
    {
        return result;
    }
    
    for (int i = 0; i < p.size(); i++)
    {
        pMap[p[i]]++;
        sTempMap[s[i]]++;
    }
    
    if (pMap == sTempMap)
    {
        result.push_back(0);
    }
    
    for (int i = (int)p.size(); i < s.size(); i++)
    {
        sTempMap[s[i]]++;
        
        sTempMapIte = sTempMap.find(s[i - p.size()]);
        
        if (sTempMapIte->first == s[i])
        {
            sTempMap[s[i - p.size()]]--;
        }
        
        else
        {
            if (sTempMapIte->second > 1)
            {
                sTempMap[sTempMapIte->first]--;
            }
            
            else
            {
                sTempMap.erase(sTempMapIte->first);
            }
        }
        
        if (pMap == sTempMap)
        {
            result.push_back(i - (int)p.size() + 1);
        }
        
    }
    
    return result;
    
}

