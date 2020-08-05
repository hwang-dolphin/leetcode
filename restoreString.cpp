
#include <iostream>
using namespace std;

#include <vector>

string restoreString(string s, vector<int>& indices)
{
    string result(s.size(), 'x');
    for (int i = 0; i < indices.size(); i++)
    {
        result[indices[i]] = s[i];
    }
    
    return result;
}

int main()
{
    string s = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};
    
    string answer = restoreString(s, indices);
    
    cout << answer << endl;
    
    return 0;
}
