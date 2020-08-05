/**
 *Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Idea: 
 Use dfs; create a map of unique TreeNode pointers with values of two vectors: leftVector and rightVector
 
 start the dfs, while backtracking, the idea is to insert every parent nodes in the map and their distant weights
 to their leftVector and rightVector.

 At the end, traverse through the map searching for leftVector and rightVector that have values of "less than equal 
 to" the "given distance value" 

 // each parent node is like a chief of the family who knows all about its chindren, grandchildren, etc.
*/



class Solution {
public:
    
    void dfs(TreeNode* ptr, map<TreeNode*, pair<vector<int>, vector<int>>> & myDataMap)
    {
        if (ptr->left == 0 && ptr->right == 0)
        {
            myDataMap[ptr];
  
            return;
        }
        
        if (ptr->left != 0)
        {
            dfs(ptr->left, myDataMap);
            
            if (myDataMap.find(ptr) == myDataMap.end())
            {
                myDataMap[ptr];
            }
            
            if (myDataMap[ptr->left].first.size() != 0 && myDataMap[ptr->left].second.size() != 0)
            {
                for (auto i: myDataMap[ptr->left].first)
                {
                    myDataMap[ptr].first.push_back(i + 1);
                }
                
                for (auto i: myDataMap[ptr->left].second)
                {
                    myDataMap[ptr].first.push_back(i + 1);
                }
            }
            
            else if (myDataMap[ptr->left].first.size() == 0 && myDataMap[ptr->left].second.size() == 0)
            {
                myDataMap[ptr].first.push_back(1);
            }
            
             else if (myDataMap[ptr->left].first.size() == 0 && myDataMap[ptr->left].second.size() != 0)
            {
         
                for (auto i: myDataMap[ptr->left].second)
                {
                    myDataMap[ptr].first.push_back(i + 1);
                }
            }
            
            else if (myDataMap[ptr->left].first.size() != 0 && myDataMap[ptr->left].second.size() == 0)
            {
         
                for (auto i: myDataMap[ptr->left].first)
                {
                    myDataMap[ptr].first.push_back(i + 1);
                }
            }
            
        }
        
        if (ptr->right != 0)
        {
            dfs(ptr->right, myDataMap);
            
            if (myDataMap.find(ptr) == myDataMap.end())
            {
                myDataMap[ptr];
            }
            
            if (myDataMap[ptr->right].first.size() != 0 && myDataMap[ptr->right].second.size() != 0)
            {
                for (auto i: myDataMap[ptr->right].first)
                {
                    myDataMap[ptr].second.push_back(i + 1);
                }
                
                for (auto i: myDataMap[ptr->right].second)
                {
                    myDataMap[ptr].second.push_back(i + 1);
                }
            }
            
             else if (myDataMap[ptr->right].first.size() == 0 && myDataMap[ptr->right].second.size() == 0)
            {
                myDataMap[ptr].second.push_back(1);
            }
            
             else if (myDataMap[ptr->right].first.size() == 0 && myDataMap[ptr->right].second.size() != 0)
            {
         
                for (auto i: myDataMap[ptr->right].second)
                {
                    myDataMap[ptr].second.push_back(i + 1);
                }
            }
            
            else if (myDataMap[ptr->right].first.size() != 0 && myDataMap[ptr->right].second.size() == 0)
            {
         
                for (auto i: myDataMap[ptr->right].first)
                {
                    myDataMap[ptr].second.push_back(i + 1);
                }
            }
        }
    }
    
    int countPairs(TreeNode* root, int distance) 
    {
        int result = 0;
        
        map<TreeNode*, pair<vector<int>, vector<int>>> myDataMap;
        map<TreeNode*, pair<vector<int>, vector<int>>>::iterator myMapIte;
        
        dfs(root, myDataMap);
        
        for (myMapIte = myDataMap.begin(); myMapIte != myDataMap.end(); ++myMapIte)
        {
            if (myMapIte->second.first.empty() == false && myMapIte->second.second.empty() == false)
            {
                for (int i = 0; i < myMapIte->second.first.size(); i++)
                {
                    for (int j = 0; j < myMapIte->second.second.size(); j++)
                    {
                        if (myMapIte->second.first[i] + myMapIte->second.second[j] <= distance)
                        {
                            result++;
                        }
                    }
                }
            }
        }
     
        return result;
    }
};
