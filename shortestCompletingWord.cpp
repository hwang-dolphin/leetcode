#include <iostream>
using namespace std;

#include <vector>
#include <map>

/*
	Intuition:  create a map of letters and their counts from licensePlate.
		    Traverse through words vector and for each element, 
		    check if its size is less than minimum; if it is, traverse through
		    this element and check if it empty out the licensePlateMap which 
	            means if it contains all letters from licensePlate.


	RunTime: O(licensePlate.size() + words.size())
	Space Complexity: O(licensePlate.size()) 

*/


string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        map<char, int> licensePlateMap;
        map<char, int> licensePlateMapTemp;
        map<char, int> wordsMap;
        int minimum = INT_MAX;
        string result;
   
        for (int i = 0; i < licensePlate.size(); i++)
        {
            if (isalpha(licensePlate[i]))
            {
                licensePlateMap[tolower(licensePlate[i])]++;
            }
        }
        
        licensePlateMapTemp = licensePlateMap;
        
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].size() < minimum)
            {
                for (int j = 0; j < words[i].size(); j++)
                {
                    if (licensePlateMapTemp.find(words[i][j]) != licensePlateMapTemp.end())
                    {
                        if (licensePlateMapTemp[words[i][j]] == 1)
                        {
                            licensePlateMapTemp.erase(words[i][j]);
                        }
                        
                        else
                        {
                            licensePlateMapTemp[words[i][j]]--;
                        }
                    }
                    
                    if (licensePlateMapTemp.empty())
                    {
                        result = words[i];
                        minimum = words[i].size();
                        break;
                    }
                }
            }
            
            licensePlateMapTemp = licensePlateMap;
        }
        
        
        
        return result;
        
    }

int main()
{
	string licensePlate = "1s3 PSt";
	vector<string> words = {"step", "steps", "stripe", "stepple"};

	string answer =  shortestCompletingWord(licensePlate, words); 

	cout << answer << endl;

	return 0;
}
