#include <iostream>
using namespace std;

#include <vector>
#include <stack>

/*
	Intuition:  This problem is bit hard to understand what it is looking for, so the intuition
		    is based on one of LeetCode's solution.  
		    The intuition starts by understanding the requirements:  
		    1) The result array should be in a range of [1, s.size() + 1]
		    2) Result array will have only unique numbers between [1, s.size() + 1]
		    3) 'I' means an increase relationship in the result array between currentIndex and currentIndex + 1
		    4) 'D' means an increase relationship in the result array between currentIndex and currentIndex + 1 
		    

		    According to LeetCode, one way to solve this problem is to push an 'indexCounter' based '1' to a stack
		    then check if s[indexCounter - 1] is 'I' or 'D'
		    If it is 'I' push_back all contents of stack to result vector
		    If it is 'D' simply do nothing

		    At the end, push_back all contents of stack to result vector to empty the remaining stack

	RunTime: O(N)
	
	Space Complexity: O(N)

*/

vector<int> findPermutation(string s) 
    {
         vector<int> result;
        stack<int> myStack;
        
        int index = 1;
        
        while (index <= s.size() + 1)
        {
            myStack.push(index);
            
            if (s[index - 1] == 'I')
            {
                while (myStack.empty() == false)
                {
                    result.push_back(myStack.top());
                    myStack.pop();
                }
            }
            
            index++;
        }
        
        while (myStack.empty() == false)
        {
            result.push_back(myStack.top());
            myStack.pop();
        }
        
        return result;
    }


int main()
{
	string s = "DDIIIID";
	vector<int> answer = findPermutation(s);

	for (auto i: answer)
	{
		cout << i << " ";
	}

	return 0;
}


