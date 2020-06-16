
/*
	Hai Wang
	Problem # 1455
        6-16-2020
*/

#include <iostream>
using namespace std;

#include <sstream>

int isPrefixOfWord(string, string);

int main()
{
    string sentence = "i love eating burger";
    string searchWord = "burg";

    int answer = isPrefixOfWord(sentence, searchWord);
    
    cout << answer << endl;
    
    return 0;
}

int isPrefixOfWord(string sentence, string searchWord)
{
    int result = -1;
    
    stringstream ss;
    string temp;
    
    ss << sentence;
    
    int index = 1;
    
    while(getline(ss, temp, ' '))
    {
        if (temp.size() >= searchWord.size())
        {
            if (temp.substr(0, searchWord.size()) == searchWord)
            {
                result = index;
                break;
            }
        }
        
        index++;
    }
    
    return result;
}


