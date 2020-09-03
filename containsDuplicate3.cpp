#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


bool customSort(pair<int, int> a, pair<int, int> b)
{
    bool answer;
    
    if (a.second < b.second)
    {
        answer = true;
    }
    
    else if (a.second > b.second)
    {
        answer = false;
    }
    
    return answer;
}


bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    bool result = false;
    
    int left;
    int right;
    int middle;
    
    long long int tAnswer;
    long long int kAnswer;
    
    vector<pair<long long int, long long int>> myVect;
    
    if (nums.size() < 2)
    {
        return false;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        myVect.push_back(make_pair(i, nums[i]));
    }
    
    sort(myVect.begin(), myVect.end(),customSort);
    
    for (int i = 0; i < myVect.size() - 1; i++)
    {
        left = i + 1;
        right = myVect.size() - 1;
        
        
        tAnswer = abs(myVect[i].second - myVect[i + 1].second);
        kAnswer = abs(myVect[i].first - myVect[i + 1].first);
        
        if (i == myVect.size() - 2)
        {
            if (tAnswer <= t && kAnswer <= k)
            {
                result = true;
            }
            
            else
            {
                result = false;
            }
            
            break;
        }
        
        while (left <= right)
        {
            middle = ((right - left) / 2) + left;
            
            tAnswer = abs(myVect[i].second - myVect[middle].second);
            kAnswer = abs(myVect[i].first - myVect[middle].first);
            
            if (tAnswer <= t && kAnswer <= k)
            {
                result = true;
                break;
            }
            
            else if (tAnswer > t)
            {
                right = middle - 1;
            }
            
            else if (tAnswer <= t && kAnswer > k)
            {
                left = middle + 1;
            }
        }
        
        if (result)
        {
            break;
        }
        
        
    }
    
    return result;
}

int main()
{
    int k = 1;
    int t = -1;
    vector<int> nums = {-1,-1};

    bool answer = containsNearbyAlmostDuplicate(nums, k, t);
    
    cout << answer << endl;
    
    return 0;
}
