#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Traverse through the the vector and sum the correspoding elements of diagonals.
		    Each pair of elements to be added to the result should have same row i number.
		    The only case they cross each other and should be added only one is when their 
		    column i element is the same.  In this case the element should be added only once.

	RunTime: O(N)
	Space Complexity: O(1)
*/



int diagonalSum(vector<vector<int>>& mat) 
    {
        int index = 0;
        int result = 0;
        
        int ai, aj, bi, bj;
        
        for (int index = 0; index < mat.size(); index++)
        {
            ai = index;
            aj = index;
            bi = index;
            bj = mat[index].size() - 1 - index;
            
            if (aj != bj)
            {
                result = result + mat[ai][aj] + mat[bi][bj];
            }
            
            else if (aj == bj)
            {
                result = result + mat[ai][aj];
            }
        }
        
        
        
        return result;
    }


int main()
{
	vector<vector<int>> mat = {{1,2,3},
              			   {4,5,6},
              			   {7,8,9}};

	int answer = diagonalSum(mat);

	cout << answer << endl;
 
	return 0;
}



