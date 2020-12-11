#include <iostream>
using namespace std;

#include <vector>

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string wordResult1;
        string wordResult2;
        
        bool result;
        
        for (int i = 0; i < word1.size(); i++)
        {
           wordResult1.append(word1[i]);
        }
        
        for (int i = 0; i < word2.size(); i++)
        {
            wordResult2.append(word2[i]);
        }
        
        if (wordResult1 == wordResult2)
        {
            result = true;
        }
        
        else
        {
            result = false;
        }
        
        return result;
    }
};

int main()
{
	vector<string> word1 = {"a", "cb"};
	vector<string> word2 = {"ab", "c"};

	Solution myObj;
	bool answer = myObj.arrayStringsAreEqual(word1, word2);

	cout << answer << endl; 

	return 0;
}
