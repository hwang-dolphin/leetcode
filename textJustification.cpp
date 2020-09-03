#include <iostream>
using namespace std;

#include <vector>

vector<string> fullJustify(vector<string>&, int);


/*
	Intuition:  Organization and modular style coding.  The 'organization coding' allowed to separate the whole problem
		    into individual smaller problems.  The first 'coding module' was to pack all words into their 
		    their corresponding strings.  The second 'coding module' took care of spaces alignments in each string
		    respecting each rule. 


	RunTime: O(N)
	Space Complexity: O(N)

*/
  
int main()
{ 
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    
    vector<string> answer = fullJustify(words, maxWidth);
    
    for (auto i: answer)
    {
        cout << i << "  " << i.size() << endl;
    }

    
    return 0;
}

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> result;
    
    vector<vector<string>> resultTemp;
    vector<string> temp;
    string tempStr = "";
    
    int spaceUsed = 0;
    
    
    for (int i = 0; i < words.size(); i++)
    {
        if (spaceUsed + (int)words[i].size() <= maxWidth)
        {
            temp.push_back(words[i]);
            spaceUsed = spaceUsed + (int)words[i].size() + 1;
            
        }

        else if (spaceUsed + (int)words[i].size() > maxWidth)
        {
            resultTemp.push_back(temp);
            temp.clear();
            spaceUsed = 0;
            
            i--;
        }
        
        // last token
        if (i == words.size() - 1)
        {
            resultTemp.push_back(temp);
            temp.clear();
            spaceUsed = 0;
        }
    }
    
    for (int i = 0; i < resultTemp.size(); i++)
    {
        if (i == resultTemp.size() - 1)
        {
            for (int j = 0; j < resultTemp[i].size(); j++)
            {
                if (j == 0)
                {
                    tempStr = resultTemp[i][j];
                    spaceUsed = spaceUsed + (int)resultTemp[i][j].size();
                }
                
                else
                {
                    tempStr = tempStr + " " + resultTemp[i][j];
                    spaceUsed = spaceUsed + 1 + (int)resultTemp[i][j].size();
                }
            }
            
            tempStr.append(maxWidth - spaceUsed, ' ');
            
            result.push_back(tempStr);
            
            tempStr.clear();
            spaceUsed = 0;
        }
        
        else if (resultTemp[i].size() == 1)
        {
            tempStr = resultTemp[i][0];
            spaceUsed = (int)resultTemp[i][0].size();
            
            tempStr.append(maxWidth - spaceUsed, ' ');
            
            result.push_back(tempStr);
            
            tempStr.clear();
            spaceUsed = 0;
        }
        
        else if (resultTemp[i].size() > 1)
        {
            int numberOfTokens = (int)resultTemp[i].size();
            int totalWhiteSpace;
            int eachEvenSpace;
            
            for (auto j : resultTemp[i])
            {
                spaceUsed = spaceUsed + (int)j.size();
            }
            
            totalWhiteSpace = maxWidth - spaceUsed;
            
            if ((totalWhiteSpace % (numberOfTokens - 1)) == 0)
            {
                eachEvenSpace = totalWhiteSpace / (numberOfTokens - 1);
            
                for (int k = 0; k < resultTemp[i].size(); k++)
                {
                    if (k == 0)
                    {
                        tempStr = resultTemp[i][k];
                    }
                    
                    else
                    {
                        tempStr.append(eachEvenSpace, ' ');
                        tempStr = tempStr + resultTemp[i][k];
                    }
                }
                
                result.push_back(tempStr);
                
                tempStr.clear();
                spaceUsed = 0;
            }
            
            // this "if else" clause was the toughest
            else if ((totalWhiteSpace % (numberOfTokens - 1)) != 0)
            {
                vector<int> totalWhiteSpaceSlotVect(numberOfTokens - 1, 0);
                
                int index = 0;
                
                while (totalWhiteSpace > 0)
                {
                    totalWhiteSpaceSlotVect[index]++;
                    totalWhiteSpace--;
                    
                    
                    index++;
                    
                    if (index >= totalWhiteSpaceSlotVect.size())
                    {
                        index = (index % totalWhiteSpaceSlotVect.size());
                    }
                }
        
                
                
                for (int k = 0; k < (resultTemp[i].size() - 1); k++)
                {
                    if (k == 0)
                    {
                        tempStr = resultTemp[i][k];
                        tempStr.append(totalWhiteSpaceSlotVect[k], ' ');
                    }
                    
                    else
                    {
                        tempStr = tempStr + resultTemp[i][k];
                        tempStr.append(totalWhiteSpaceSlotVect[k], ' ');
                    }
                }

                tempStr = tempStr + resultTemp[i][resultTemp[i].size() - 1];
                
                result.push_back(tempStr);
                
                tempStr.clear();
                spaceUsed = 0;
                totalWhiteSpaceSlotVect.clear();
            }
        }
    }
    
    return result;
}
