#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

/*
	Intuition:  Sorting the products in lexicographical order, then use brute force

	RunTime: O(MN), M = size of products, N = size of searchWord

	Space Complexity: O(MN)
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        vector<vector<string>> result;
        vector<string> temp;
    
        sort(products.begin(), products.end());
        int counter = 0;
    
        for (int i = 0; i < searchWord.size(); i++)
        {
            for (int j = 0; j < products.size(); j++)
            {
                if (searchWord.substr(0, i + 1) == products[j].substr(0, i + 1))
                {
                    temp.push_back(products[j]);
                    counter++;
                }
            
                if (counter == 3)
                {
                    result.push_back(temp);
                    temp.clear();
                    counter = 0;
                    break;
                }
            
                if (j == products.size() - 1)
                {
                    result.push_back(temp);
                    temp.clear();
                    counter = 0;
                }
            }
        }
    
        return result;
    }
};


int main()
{
	vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
	string searchWord = "mouse";

	Solution myObj;
	vector<vector<string>> answer  = myObj.suggestedProducts(products, searchWord);

	for (auto i: answer)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}

		cout << endl;
	}
 
	return 0;
}
