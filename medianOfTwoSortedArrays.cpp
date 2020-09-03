#include <iostream>
using namespace std;

#include <vector> 

/*
	Intuition:  Simply combine the two arrays into a new array in ascending order.
		    From this new array, simply find the median of this new array.  One way
		    to find it is by checking the size of this new array, when it is odd or even.
		    
		    The tricky part was to figure out when one of the two given arrays would be empty.
		    In C++, C++ does not allow to assign "NULL" value to its integer.  C++ allows it but
		    it is the same as assigning 0 to it which confuses with the actual 0.

		    A custom made "NULL" value was created by checking the limits of "int" [-2147483648, +2147483647].
		    Since the given arrays are vector of "int".  Any number outside the range of "signed int" would be fine.
		    Long long int is a nice type to give to this new "custom null".

	RunTime:    O(m + n) linear
	Space Complexity: O(m + n)
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
 {
    double result;
    vector<int> newNums;
    
    int i = 0;
    int j = 0;
    
    long long int aTemp;
    long long int bTemp;
        
    const long long int CUSTOMNULL = 4000000000;
    
    while(i < nums1.size() || j < nums2.size())
    {
        aTemp = (i < nums1.size()) ? nums1[i]: CUSTOMNULL;
       
        bTemp = (j < nums2.size()) ? nums2[j]: CUSTOMNULL;
        
        if (aTemp !=  CUSTOMNULL && bTemp != CUSTOMNULL)
        {
            if (aTemp <= bTemp)
            {
                newNums.push_back(aTemp);
                i++;
            }
            
            else if (aTemp > bTemp)
            {
                newNums.push_back(bTemp);
                j++;
            }
        }
        
        else if (aTemp == CUSTOMNULL)
        {
            newNums.push_back(bTemp);
            j++;
        }
        
        else if (bTemp == CUSTOMNULL)
        {
            newNums.push_back(aTemp);
            i++;
        }
    }
    
    if (newNums.size() % 2 == 0)
    {
        result = (double)(newNums[newNums.size() / 2] + newNums[(newNums.size() / 2) - 1]) / 2;
    }
    
    else if (newNums.size() % 2 != 0)
    {
        result = (double)newNums[newNums.size() / 2];
    }
    
    
    return result;
  
}

int main()
{
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2};

	double answer = findMedianSortedArrays(nums1, nums2); 	

	cout << answer << endl;

	return 0;
}
