#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition: In version one, as soon as find a "1" value, traverse its row and traverse its column 
		   to see if it is the only one "1" value.  If yes, counter is incremented.

		   In version two, keep a bookkeeping track of rows and columns.  Build it by traversing 
		   the 2 dimensional array one time.
		   Traverse the 2 dimensional array again, if found "1" then search arrays rows and array columns
		   to see if it is unique.

	RunTime: O(N^2)
	Space Complexity: Version 1, O(N); version 2 O(1)

*/


int numSpecialV2(vector<vector<int>>& mat) 
    {
        int counter = 0;
        bool found = true;
        
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    for (int m = 0; m < mat[i].size(); m++)
                    {
                        if (mat[i][m] == 1 && m != j)
                        {
                            found = false;
                            break;
                        }
                    }
                    
                    if (found == true)
                    {
                        for (int n = 0; n < mat.size(); n++)
                        {
                            if (mat[n][j] == 1 && n != i)
                            {
                                found = false;
                                break;
                            }
                        }
                    }
                    
                    if (found)
                    {
                        counter++;
                    }
                    
                    found = true;
                }
            }
        }
        
        return counter;
    }

int numSpecial(vector<vector<int>>& mat) 
    {
        int counter = 0;
    
        vector<int> rows(mat.size(), 0);
        vector<int> columns(mat[0].size(), 0);
       
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    rows[i]++;
                    columns[j]++;
                }
            }
        }
        
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1 && rows[i] == 1 && columns[j] == 1)
                {
                    counter++;
                }
            }
        }
        
        return counter;
    }


int main()
{
	vector<vector<int>> mat = {{1,0,0},
              			   {0,0,1},
              			   {1,0,0}};

	int answer = numSpecial(mat);

	cout << answer << endl;
 		
	return 0;
}
