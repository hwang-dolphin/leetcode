#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Use LeetCode's solution 'backtracking'.  The tough part was to decide 
	how to loop the initial finite loop (which choices to make).  Ended up being
	loop from [1, 9] and when combination has reached K size of sum is equal to N then
	we found a combination otherwise we have not found (both base cases).

	It is a brute force backtracking in the paper.
*/



class Solution 
{
private:
    int sum = 0;
    vector<vector<int>> results;
    int myK, myN;

public:
    
    void backtrack(vector<int> temp, int ptr) 
    {
        if (temp.size() == myK && sum == myN)
        {
            results.push_back(temp);
            return;
        }
        
        else if (temp.size() == myK || sum > myN)
        {
            return;
        }
        
        for (int i = ptr; i < 9; i++)
        {
            temp.push_back(i + 1);
            sum = sum + (i + 1);
            
            backtrack(temp, i + 1);
            
            sum = sum - temp[temp.size() - 1];
            temp.erase(temp.begin() + temp.size() - 1);
        }
        
    }

    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> temp;
    
        myK = k;
        myN = n;
        
        backtrack(temp, 0);
        return results;
    }
};

int main()
{
	int k = 3;
	int n = 9;

	vector<vector<int>> myResult;

	Solution mySolution;

        myResult = mySolution.combinationSum3(k, n);

	for (auto i: myResult)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		
		cout << endl;
	}			

	return 0;
}
