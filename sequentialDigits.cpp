#include <iostream>
using namespace std;

#include <vector>

/*
	Intuition:  Use of sliding window in a smart way.

*/

vector<int> sequentialDigits(int low, int high)
{
    vector<int> result;
    
    string nums = "123456789";
    int temp;
    
    string lowStr = to_string(low);
    string highStr = to_string(high);
    
    int windowMinSize = (int)lowStr.size();
    int windowMaxSize = (int)highStr.size();
    int left;

    int currWindowSize = windowMinSize;
    
    while (currWindowSize <= windowMaxSize)
    {
        for (int right = currWindowSize - 1; right < nums.size(); right++)
        {
            left = right - currWindowSize + 1;
        
            temp = stoi(nums.substr(left, currWindowSize), 0, 10);
        
            if (temp >= low && temp <= high)
            {
                result.push_back(temp);
            }
        }
        
        currWindowSize++;
    }
    
    return result;
}

int main()
{
    int low = 1000;
    int high = 1000000000;
    
    vector<int> answer = sequentialDigits(low, high);
    
    for (auto i: answer)
    {
        cout << i << endl;
    }
        
    return 0;
}
   
