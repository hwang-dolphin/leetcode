#include <iostream>
using namespace std;

#include <map>

/*
	Intuition:  Try to formulate every possible test case output:
				First, when both string sizes are different or both sizes are equal 
				to zero then return false.
				   
				Second, both strings are equal and they have sizes greater than or equal to two,
				return false if all letters in each string are unique.  If letters are not unique,
				return true.

				Third, after passing all above test cases; check if both strings has 
				exactly two letters that differs from each other.  Then swap it, if it is equal 
				return true otherwise return false for any other combinations. 				 

	RunTime: O(N)
	Space Complexity: O(N)
*/



class Solution {
public:
    bool buddyStrings(string A, string B) 
    {
        bool result = false;
        int counter = 0;
        int first;
        int second;
        
        map<char, int> myMap;
        map<char, int>::iterator myIte;
        
        if (A.size() != B.size() ||
            (A.size() == 0 && B.size() == 0))
        {
            return false;
        }
        
        if (A == B && 
           (A.size() >= 2 && B.size() >= 2))
        {
            for (int i = 0; i < A.size(); i++)
            {
                myMap[A[i]]++;
            }
            
            for (myIte = myMap.begin(); myIte != myMap.end(); myIte++)
            {
                if (myIte->second >= 2)
                {
                    result = true;
                    break;
                }
            }
            
            return result;
        }       
        
        
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != B[i])
            {
                counter++;
                
                if (counter == 1)
                {
                    first = i;
                }
                
                else if (counter == 2)
                {
                    second = i;
                }
            }
            
            if (counter > 2)
            {
                result = false;
                break;
            }
        }
        
        if (counter == 2)
        {
            swap(A[first], A[second]);
            if (A == B)
            {
                result = true;
            }
        }        
        
        
        return result;
    }
};

int main()
{
	string A = "ab";
	string B = "ab";

	Solution myObj;

	bool answer = myObj.buddyStrings(A, B);

	cout << answer << endl;	

	return 0;
}
