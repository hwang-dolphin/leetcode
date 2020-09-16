#include <iostream>
using namespace std;

#include <vector>

vector<int> numberOfLines(vector<int>& widths, string S) 
    {
        int sum = 0;
        int linesCount = 1;
        
        for (int i = 0; i < S.size(); i++)
        {
            if (sum + widths[S[i] - 'a'] > 100)
            {
                linesCount++;
                sum = widths[S[i] - 'a'];
            }
            
            else
            {
                sum = sum + widths[S[i] - 'a'];
            }
        }
        
        return {linesCount, sum};
    }

int main()
{
	vector<int> widths = {18,12,56};
	string S = "abc";
	vector<int> answer = numberOfLines(widths, S);

	cout << answer[0] << " " << answer[1] << endl;

	return 0;
}
