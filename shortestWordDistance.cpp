#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <climits>

/*
	Intuition:  Create a map, key string and value vector of int, then add
		    all element indexes to the same key string.
		    Traverse through both these vector<int> of indexes looking for the shortest 
		    value.

	RunTime: O(N^2)
	Space Complexity: O(N)

*/


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        map<string, vector<int>> myMap;
    vector<int> word1Vect;
    vector<int> word2Vect;
    
    int result = INT_MAX;
    
    for (int i = 0; i < words.size(); i++)
    {
        myMap[words[i]].push_back(i);
    }
    
    word1Vect = myMap[word1];
    word2Vect = myMap[word2];
    
    for (int i = 0; i < word1Vect.size(); i++)
    {
        for (int j = 0; j < word2Vect.size(); j++)
        {
            if (abs(word1Vect[i] - word2Vect[j]) < result)
            {
                result = abs(word1Vect[i] - word2Vect[j]);
            }
        }
    }
    
    return result;

    }
};

int main()
{
	vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    	string word1 = "coding";
    	string word2 = "practice";

	Solution myObj;
	int answer = myObj.shortestDistance(words, word1, word2);
	
    	cout << answer << endl;	

	return 0;

}
