#include <iostream>
using namespace std;

#include <vector> 


// dp very similar to finobacci's dp problem

vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        
        if (numRows == 0)
        {
            return result;
        }
        
        else if (numRows == 1)
        {
            result.push_back({1});
            return result;
        }
        
        else if (numRows == 2)
        {
            result.push_back({1});
            result.push_back({1,1});
            return result;
        }
        
        else
        {
            result.push_back({1});
            result.push_back({1,1});
            
            int index = 1;
            
            while(index < numRows - 1)
            {
                for (int i = 1; i < result[index].size(); i++)
                {
                    temp.push_back(result[index][i - 1] + result[index][i]);
                }
            
                temp.insert(temp.begin(), 1);
                temp.push_back(1);
                
                result.push_back(temp);
                
                temp.clear();
                
                index++;
            }
        }
        
        return result;
    }


int main()
{
	int numRows = 5;

	vector<vector<int>> answer = generate(numRows);

	for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
		{
			cout << answer[i][j] << " ";
		}	
		
		cout << endl;
	}
	
	return 0;
}
