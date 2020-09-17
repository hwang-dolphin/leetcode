#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  First case, if sentence1 and sentence2 have different sizes then result is false.
		    Traverse through sentence1 and sentence2 at the same time.  For elements of sentence1[i] 
		    and sentence2[i] that are different, check if they are found in the similarPairs.
		    Check both {sentence1[i], sentence2[i]} and {sentence2[i], sentence1[i]} if they
		    are found in similarPairs; if not found, they result is false.

	RunTime: O(N)
	Space Complexity: O(1)
*/


bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) 
    {
        
        bool result = true;
        vector<string> temp1, temp2;
        
        if (sentence1.size() != sentence2.size())
        {
            return false;
        }
        
        for (int i = 0; i < sentence1.size(); i++)
        {
            if (sentence1[i] != sentence2[i])
            {
                temp1 = {sentence1[i], sentence2[i]};
                temp2 = {sentence2[i], sentence1[i]};
                
                if (find(similarPairs.begin(), similarPairs.end(), temp1) == similarPairs.end() && find(similarPairs.begin(), similarPairs.end(), temp2) == similarPairs.end())
                {
                    result = false;
                    break;
                }
            }
        }
        
        return result;
    }

int main()
{
	vector<string> sentence1 = {"great","acting","skills"};
	vector<string> sentence2 = {"fine","drama","talent"};

	vector<vector<string>> similarPairs = {{"great","fine"},{"drama","acting"},{"skills","talent"}};

	bool answer = areSentencesSimilar(sentence1, sentence2, similarPairs);

	cout << answer << endl; 

	return 0;
}
