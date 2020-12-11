#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Simple binary search taking advantage that inner vectors are sorted in ascending order.
				RunTime: O Log(N)
				Space Complexity: O(1) 
*/


// this function is not needed since the array elements already come sorted
// this function is just left here for future reference purposes
bool customSort(vector<int> a, vector<int> b)
{
    bool result = false;
        
    if (a[a.size() - 1] < b[0])
    {
        result = true;
    }
        
    return result;
}



class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool result = false;
        
        if (matrix.size() == 0)
        {
            return false;
        }
        
        else if (matrix.size() == 1)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                if (matrix[0][i] == target)
                {
                    result = true;
                    break;
                }
            }
            
            return result;
        }
        
        sort(matrix.begin(), matrix.end(), customSort);
        
        int left = 0;
        int right = matrix.size() - 1;
        int middle;
        
        while (left <= right)
        {
            middle = ((right - left) / 2) + left;

            if (target >= matrix[middle][0] && target <= matrix[middle][matrix[middle].size() - 1])
            {
                for (int i = 0; i < matrix[middle].size(); i++)
                {
                    if (target == matrix[middle][i])
                    {
                        result = true;
                        break;
                    }
                }
                
                break;
            }
            
            else if (target < matrix[middle][0])
            {
                right = middle - 1;
            }
            
            else if (target > matrix[middle][matrix[middle].size() - 1])
            {
                left = middle + 1;
            }
        }
        
        return result;
    }
};


int main()
{
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	int target = 13;

	Solution myObj; 

	bool answer = myObj.searchMatrix(matrix, target);

	cout << answer << endl;	

	return 0;
}
