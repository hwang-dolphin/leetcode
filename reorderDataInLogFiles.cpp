#include <iostream>
using namespace std;

#include <vector>   
#include <algorithm>


/*
	Intuition: Just normal custom sort by the sorting can not happen everything at once.  The digits need to be removed
		   only the letter-logs should be sorted in the customSort.

	RunTime: NLOG(N)
	Space Complexity: (N) 
*/


bool customSort(string & a, string & b)
    {
        bool result;
        
        size_t aSpaceIndex = a.find_first_of(' ');
        size_t bSpaceIndex = b.find_first_of(' ');
        
     
            if (a.substr(aSpaceIndex + 1, string::npos) < b.substr(bSpaceIndex + 1, string::npos))
            {
                result = true;
            }
            
            else if (a.substr(aSpaceIndex + 1, string::npos) > b.substr(bSpaceIndex + 1, string::npos))
            {
                result = false;
            }
            
        
            else if (a.substr(aSpaceIndex + 1, string::npos) == b.substr(bSpaceIndex + 1, string::npos))
            {
                if (a.substr(0, aSpaceIndex) < b.substr(0, bSpaceIndex))
                {
                    result = true;
                }
                
                else if (a.substr(0, aSpaceIndex) > b.substr(0, bSpaceIndex))
                {
                    result = false;
                }
            }

        return result;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        vector<string> digit;
        vector<string> alpha;
        
        for (auto i: logs)
        {
            if (isdigit(i[i.find_first_of(' ') + 1]))
            {
                digit.push_back(i);
            }
            
            else
            {
                alpha.push_back(i);
            }
        }
        
        sort(alpha.begin(), alpha.end(), customSort);
        
        for (auto i: digit)
        {
            alpha.push_back(i);
        }
        
        return alpha;
    }

int main()
{
	vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 art zero","let3 art zero"};
	vector<string> answer = reorderLogFiles(logs);

	for (auto i: answer)
	{
		cout << i << endl;
	}

	return 0;
}
