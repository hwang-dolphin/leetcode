

#include <iostream>
using namespace std;

#include <vector>

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
{
    bool result = true;
    
    if (rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1])
    {
        result = false;
    }

    return result;
}

int main()
{
    vector<int> rec1 = {0,0,1,1};
    vector<int> rec2 = {1,0,2,1};
    
    bool answer = isRectangleOverlap(rec1, rec2);
    
    cout << answer << endl;
    
    return 0;
}



