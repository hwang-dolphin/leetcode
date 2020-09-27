#include <iostream>
using namespace std;

#include <map>

/*
	Intuition: it should not be printed if timestamp difference is [0, 9]
	RunTime: O(1)	
	Space Complexity: O(N)
*/

class Logger 
{
private:
    map<string, int> myMap;
    
public:
    /** Initialize your data structure here. */
    Logger() {
  
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) 
    {
        // not found
        bool answer = true;
        
        if (myMap.find(message) != myMap.end())
        {
            if (timestamp - myMap[message] < 10)
            {
                answer = false;
            }
            
            else
            {
                myMap.erase(message);
                myMap.insert(make_pair(message, timestamp));
            }
        }
        
        else
        {
            myMap.insert(make_pair(message, timestamp));
        }
        
        return answer;
    }
};


int main()
{
	Logger* logger = new Logger();
	bool answer;
	answer = logger->shouldPrintMessage(1, "foo");
	cout << answer << endl; 

	answer = logger->shouldPrintMessage(2,"bar");
	cout << answer << endl;

	answer = logger->shouldPrintMessage(3,"foo");
	cout << answer << endl; 

	answer = logger->shouldPrintMessage(8,"bar");
	cout << answer << endl;

	answer = logger->shouldPrintMessage(10,"foo");
	cout << answer << endl;

	answer = logger->shouldPrintMessage(11,"foo");
	cout << answer << endl;
	
	return 0;
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
