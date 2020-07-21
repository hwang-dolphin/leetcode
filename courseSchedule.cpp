#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <set>
#include <queue>

bool canFinish(int, vector<vector<int>>&);

int main()
{
    int numCourses = 2;
    
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    
    bool answer = canFinish(numCourses, prerequisites);
    
    cout << answer << endl;
    
    return 0;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    bool result;
    
    map<int, vector<int>> myAdjListMap;
    map<int, int> inDegreeMap;
    
    set<int> uniqueCoursesSet;
    
    queue<int> myQueue;
    
    int counter = 0;
    
    
    for (auto i: prerequisites)
    {
        myAdjListMap[i[1]].push_back(i[0]);
        
        uniqueCoursesSet.insert(i[0]);
        uniqueCoursesSet.insert(i[1]);
    }
    
    for (auto i: uniqueCoursesSet)
    {
        myAdjListMap[i];
        
        inDegreeMap.insert(make_pair(i, 0));
    }
    
    for (auto i: myAdjListMap)
    {
        for (auto j : i.second)
        {
            inDegreeMap[j]++;
        }
    }
    
    for (auto i: inDegreeMap)
    {
        if (i.second == 0)
        {
            myQueue.push(i.first);
        }
    }
    
    while (myQueue.empty() == false)
    {
        for (auto i: myAdjListMap[myQueue.front()])
        {
            inDegreeMap[i]--;
            
            if (inDegreeMap[i] == 0)
            {
                myQueue.push(i);
            }
        }
        
        myQueue.pop();
        counter++;
    }
    
    result = (counter == uniqueCoursesSet.size()) ? true : false;
    
    return result;
}


