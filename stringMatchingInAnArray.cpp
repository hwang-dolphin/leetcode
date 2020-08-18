    
#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Sort the given array of strings by the size of each elements.  The trick is
		    a subtring is smaller than the a string therefore we do a "brute force" of a sorted
		    given array by size of elements and we will find the result.
		    Use a customSort, and in the result vector try to not add repetitive elements.

	RunTime: O(N^2)
	Space Complexity: O(N) 

*/


bool customSort(string a, string b)
    {
        return (a.size() < b.size()) ? true : false;
    }
    
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> result;
        
        if (words.size() == 1)
        {
            return result;
        }
        
        sort(words.begin(), words.end(), customSort);
        
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        
        return result;
    }


int main()
{
	vector<string> words = {"leetcoder","leetcode","od","hamlet","am"};

	vector<string> answer = stringMatching(words);

	for (auto i: answer)
	{
		cout << i << endl;
	}	

	return 0;
}
