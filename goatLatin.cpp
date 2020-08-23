#include <iostream>
using namespace std;

#include <sstream>

/*
	Intuition:  Simple naive approach meeting the requirement rules of the question.
	
	
	Space Complexity: O(1)
*/


string toGoatLatin(string S) 
    {
              stringstream ss;
    string temp;
    string result = "";
    ss << S;
    
    int index = 1;
    while(getline(ss, temp, ' '))
    {
        
        
        if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' ||
            temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U')
        {
            temp.append("ma");
            
            for (int i = 0; i < index; i++)
            {
                    temp.push_back('a');
            }
        }
        
        else
        {
            temp.push_back(temp[0]);
            temp.erase(temp.begin());
            temp.append("ma");
            
            for (int i = 0; i < index; i++)
            {
                temp.push_back('a');
            }
        }
        
        result.append(temp + " ");
        
        index++;
    }
    
    result.erase(result.end() - 1);
    
    return result;
        
        
    }

int main()
{
	string S = "I speak Goat Latin";
	string answer = toGoatLatin(S);

	cout << answer << endl;		

	return 0;
}
