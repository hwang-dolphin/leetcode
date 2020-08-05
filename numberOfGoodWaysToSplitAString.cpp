#include <iostream>
using namespace std;

int numSplits(string s)
{
    // create and use two data structure such as arrays,leftArray and rightArray, to keep track 
    // of keys and values
    // tranverse from left to right updating both arrays and comparing them both if they have unique
    // keys that are equal in both amounts
    // very similar to sliding window of two windows, left and right windows (pointer begin to pointer i - 1)
    // (pointer i to n - 1), but using only one pointer 
    // runtime: O(N)
    // space: O(1)


    int leftArray[26];
    int rightArray[26];
    
    memset(leftArray, 0, sizeof(leftArray));
    memset(rightArray, 0, sizeof(rightArray));
    
    int leftUniqueCounter = 0;
    int rightUniqueCounter = 0;
    
    int result = 0;
    
    if (s.size() == 1)
    {
        return 0;
    }
    
    leftArray[s[0] - 'a']++;
    leftUniqueCounter++;
    
    for (int i = 1; i < s.size(); i++)
    {
        rightArray[s[i] - 'a']++;
        
        if (rightArray[s[i] - 'a'] == 1)
        {
            rightUniqueCounter++;
        }
    }
    
    if (leftUniqueCounter == rightUniqueCounter)
    {
        result++;
    }
    
    
    for (int i = 1; i < s.size() - 1; i++)
    {
        leftArray[s[i] - 'a']++;
        rightArray[s[i] - 'a']--;
        
        if (leftArray[s[i] - 'a'] == 1)
        {
            leftUniqueCounter++;
        }
        
        if (rightArray[s[i] - 'a'] == 0)
        {
            rightUniqueCounter--;
        }
        
        if (leftUniqueCounter == rightUniqueCounter)
        {
            result++;
        }
    }
    
    return result;
}


int main()
{
    int answer;
    
    string s = "aacaba";
    
    answer = numSplits(s);
    
    cout << answer << endl;
    
    return 0;
}
 
