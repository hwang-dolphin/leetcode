/**
 * Definition for a binary tree node.
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
	Intuition:  use normal dfs visiting all left nodes to right nodes (inorder traversal)
		    add the node values this way.
		    use variable x as x coordinate and variable y as y coordinate
		    use a map of int x, and values as vector of pair (nodeValue, yCoordinate)

		    use a custom sort to sort the vector of pairs according to their 
		    yCoordinate values.  Node near root should have priority, if tied
		    then the value of node that is less should have priority

		    clean up and store in result vector

	
	Runtime Complexity: O(2^depth) or O(n logn) whichever is slower  

	Space complexity: O(number of nodes)  


*/



class Solution {
public:
    
    static bool customSort(pair<int, int> & a, pair<int, int> & b)
    {
        if (a.second < b.second)
        {
            return true;
        }
        
        else if (a.second == b.second)
        {
            if (a.first < b.first)
            {
                return true;
            }
            
            else 
            {
                return false;
            }
        }
        
        else
        {
            return false;
        }
    }
    
    void dfs(TreeNode* & ptr, map<int, vector<pair<int, int>>> & myMap, int & xCoor, int & yCoor)
    {
        myMap[xCoor].push_back(make_pair(ptr->val, yCoor));
        
        if (ptr->left == 0 && ptr->right == 0)
        {
            return;
        }
        
        else
        {
            if (ptr->left != 0)
            {
                xCoor--;
                yCoor++;
                dfs(ptr->left, myMap, xCoor, yCoor);
                xCoor++;
                yCoor--;
            }
            
            if (ptr->right != 0)
            {
                xCoor++;
                yCoor++;
                dfs(ptr->right, myMap, xCoor, yCoor);
                xCoor--;
                yCoor--;
            }
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        map<int, vector<pair<int, int>>> myMap;
        
        vector<int> temp;
        
        int xCoor = 0;
        int yCoor = 0;
        
        if (root == 0)
        {
            return result;
        }
        
        else
        {
            dfs(root, myMap, xCoor, yCoor);
            
            for (auto & i: myMap)
            {
                sort(i.second.begin(), i.second.end(), customSort);
                
                for (auto j : i.second)
                {
                    temp.push_back(j.first);
                }
                
                result.push_back(temp);
                
                temp.clear();
            }
        }
    
        return result;
    }
};
