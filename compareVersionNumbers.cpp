#include <iostream>
using namespace std;

#include <vector>
#include <sstream>

/*
	Intuition:  reformat both string versions making them equal size
		    in numbers of dots by adding dot and zeros to the end of the 
		    end of the shortest string.
		    Use two vectors to hold values of numbers between the dots.

		    Compare the values of both vectors holding values.
		    ** the coding part would be very complicated if not using two
		    ** vectors to hold values for later comparison

	RunTime: O(N)
	Space Complexity: O(N)
*/



int compareVersion(string version1, string version2)
{
    int version1DotCount = 0;
    int version2DotCount = 0;
    int differenceDotCount;
    
    vector<int> version1Vect;
    vector<int> version2Vect;
    
    stringstream ss;
    string temp;
    
    int result = 0;
    
    if (version1.size() == 0 && version2.size() == 0)
    {
        return 0;
    }
    
    else if (version1.size() != 0 && version2.size() == 0)
    {
        return 1;
    }
    
    else if (version1.size() == 0 && version2.size() != 0)
    {
        return -1;
    }
    
    
    
    for (int i = 0; i < version1.size(); i++)
    {
        if (version1[i] == '.')
        {
            version1DotCount++;
        }
    }
    
    for (int i = 0; i < version2.size(); i++)
    {
        if (version2[i] == '.')
        {
            version2DotCount++;
        }
    }
    
    if (version1DotCount > version2DotCount)
    {
        differenceDotCount = version1DotCount - version2DotCount;
        
        for (int i = 0; i < differenceDotCount; i++)
        {
            version2.push_back('.');
            version2.push_back('0');
        }
    }
    
    else if (version2DotCount > version1DotCount)
    {
        differenceDotCount = version2DotCount - version1DotCount;
        
        for (int i = 0; i < differenceDotCount; i++)
        {
            version1.push_back('.');
            version1.push_back('0');
        }
    }
    
    ss << version1;
    
    while (getline(ss, temp, '.'))
    {
        version1Vect.push_back(stoi(temp));
    }
    
    ss.clear();
    temp.clear();
    
    ss << version2;
    
    while (getline(ss, temp, '.'))
    {
        version2Vect.push_back(stoi(temp));
    }
    
    for (int i = 0; i < version1Vect.size(); i++)
    {
        if (version1Vect[i] > version2Vect[i])
        {
            result = 1;
            break;
        }
        
        else if (version1Vect[i] < version2Vect[i])
        {
            result = -1;
            break;
        }
    }
    
    return result;
}

int main()
{
    string version1 = "1.0";
    string version2 = "1.0.0";
    
    int answer = compareVersion(version1, version2);
    
    cout << answer << endl;
    
    return 0;
}

