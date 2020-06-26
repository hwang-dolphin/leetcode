#include <iostream>
using namespace std;

#include <vector>

vector<vector<int>> flipAndInvertImage(vector<vector<int>>&); 

int main()
{
	vector<vector<int>> A = {{1,1,0}, {1,0,1}, {0,0,0}};

	vector<vector<int>> answer = flipAndInvertImage(A);

	for (auto i: answer)
	{
		for (int j = 0; j < i.size(); j++)
		{
			cout << i[j] << " "; 
		}

		cout << endl;
	}


	return 0;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
{
        int temp;
        int left, right;
        
        for (auto & i: A)
        {
            left = 0;
            right = i.size() - 1;
            
            while (left < right)
            {
                temp = i[left];
                i[left] = i[right];
                i[right] = temp;
                
                left++;
                right--;
            }
        }
        
        for (auto & i: A)
        {
            for (int j = 0; j < i.size(); j++)
            {
                if (i[j] == 1)
                {
                    i[j] = 0;
                }
                
                else if (i[j] == 0)
                {
                    i[j] = 1;
                }
            }
        }
        
        return A;
}
