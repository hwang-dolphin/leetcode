
#include <iostream>
using namespace std;

#include <sstream>
#include <stack>

string reverseWords(string s)
{
    string result = "";
    
    stringstream ss;
    stack<string> myStack;
    
    ss << s;
    
    string temp;
    
    while(getline(ss, temp, ' '))
    {
        if (temp != "")
        {
            myStack.push(temp);
        }
    }
    
    while(myStack.empty() == false)
    {
        if (myStack.size() > 1)
        {
            result.append(myStack.top() + " ");
        }
        
        else if (myStack.size() == 1)
        {
            result.append(myStack.top());
        }
       
        myStack.pop();
    }
    
    return result;
}

int main()
{
    string s = "  hello world!  ";
    
    string answer = reverseWords(s);
    
    cout << answer << endl;
    
    return 0;
}
