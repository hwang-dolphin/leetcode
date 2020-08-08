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
class Solution {
public:
   
    
     /*
          Intuition:  
	  Problems "Binary Tree Level Order Traversal" and "Binary Tree Level Order Traversal 2"
	  has the same code but only changes the order of traversing through the map of level key and 
	  vector of values when adding to the result vector of vectors.          

	  Use dfs and an integer 'level' to help track the current level of the tree.  Add
          each node value and its 'level' while front traversing the tree (not the backtracking traversal).
          Use a map of key int and vector<int> as value.
  
          After dfs traverse through the map and insert to result vector.
  
          Run Time: O(2^Depth) or O(N) whichever takes longer time
          Space Complexity: O(N)  
      */



 
    void dfs(TreeNode* & ptr, vector<vector<int>> & result, map<int, vector<int>> & myMap, int & level)
    {
        myMap[level].push_back(ptr->val);
        
        if (ptr->left == 0 && ptr->right == 0)
        {
            return;
        }
        
        else
        {
            if (ptr->left != 0)
            {
                level++;
                dfs(ptr->left, result, myMap, level);
                level--;
                
            }
            
            if (ptr->right != 0)
            {
                level++;
                dfs(ptr->right, result, myMap, level);
                level--;
            }
        }
    }

    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        map<int, vector<int>> myMap;
        
        map<int, vector<int>>::iterator it;
        
        int level = 0;
        
        if (root == 0)
        {
            return result;
        }
    
        dfs(root, result, myMap, level);
        
        for (it = myMap.begin(); it != myMap.end(); ++it)
        {
            result.push_back(it->second);
        }
        
        return result;

    }
};
