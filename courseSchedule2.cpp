class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
          vector<int> result;
    map<int, vector<int>> myAdjListMap;
    map<int, vector<int>>::iterator myAdjListMapIte;
    
    set<int> uniqueVerticesSet;
    
    map<int, int> inDegreeVerticesMap;
    
    queue<int> myQueue;
    int counter = 0;
        
    if (prerequisites.size() == 0)
    {
        for (int i = 0; i < numCourses; i++)
        {
            result.push_back(i);
        }
        
        return result;
    }
    
    for (auto i: prerequisites)
    {
        myAdjListMap[i[1]].push_back(i[0]);
        uniqueVerticesSet.insert(i[0]);
        uniqueVerticesSet.insert(i[1]);
    }
    
    for (auto i: uniqueVerticesSet)
    {
        myAdjListMap[i];
    }
    
    for (auto i: uniqueVerticesSet)
    {
        inDegreeVerticesMap.insert(make_pair(i, 0));
    }
    
    for (myAdjListMapIte = myAdjListMap.begin(); myAdjListMapIte != myAdjListMap.end(); ++myAdjListMapIte)
    {
        for (auto i: myAdjListMapIte->second)
        {
            inDegreeVerticesMap[i]++;
        }
    }
    
    for (auto i: inDegreeVerticesMap)
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
            inDegreeVerticesMap[i]--;
        
            if (inDegreeVerticesMap[i] == 0)
            {
                myQueue.push(i);
            }
        }
        
        result.push_back(myQueue.front());
        
        myQueue.pop();
        
        counter++;
    }
    
    if (counter != uniqueVerticesSet.size())
    {
        result.clear();
    }
    
    else
    {
        int missingCourses = numCourses - 1;
        
        if (result.size() != numCourses)
        {
            while (result.size() != numCourses)
            {
                if (find(result.begin(), result.end(), missingCourses) == result.end())
                {
                    result.insert(result.begin(), missingCourses);
                }
                
                else
                {
                    missingCourses--;
                }
            }
        }
    }
        
    return result;
    }
};
