/*
	Hai Wang
	841. Keys and Rooms 
	BFS
	6-20-2020
*/


#include <iostream>
using namespace std;

#include <map>
#include <vector>
#include <queue>

bool canVisitAllRooms(vector<vector<int>>&);

int main()
{
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    
    bool answer = canVisitAllRooms(rooms);
    
    cout << answer << endl;
    
    return 0;
}

bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    // bfs
    map<int, vector<int>> myAdjacencyListMap;
    queue<int> myQueue;
    vector<int> visited;

    for (int index = 0; index < rooms.size(); index++)
    {
        myAdjacencyListMap.insert(make_pair(index, rooms[index]));
    }
    
    myQueue.push(0);
    visited.push_back(0);
    
    while (myQueue.empty() == false)
    {
        int myFront = myQueue.front();
        myQueue.pop();
        
        for (auto i: myAdjacencyListMap[myFront])
        {
            if (find(visited.begin(), visited.end(), i) == visited.end())
            {
                myQueue.push(i);
                visited.push_back(i);
            }
        }
    }
    
    return (visited.size() == myAdjacencyListMap.size()) ? true : false;
}



