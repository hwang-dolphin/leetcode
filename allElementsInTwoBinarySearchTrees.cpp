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
	Intuition:  Simple traversal through both trees using dfs.  Use a result vector
		    to store all node values as it traverses through the tree.  Traverse through
		    the second tree using the same result vector.
		    After traversing through both trees using dfs and storing their node values 
		    to the same result vector, simply sort this result vector in ascending order.
	
	RunTime: O(NLog(N)) 
	Space Complexity: O(N) 
*/

class Solution {
public:
    void dfs(TreeNode* ptr, vector<int> & treeVect)
    {
        if (ptr == 0)
        {
            return;
        }
        
        treeVect.push_back(ptr->val);
 
        if (ptr->left == 0 && ptr->right == 0)
        {
            return;
        }
        
        if (ptr->left != 0)
        {
            dfs(ptr->left, treeVect);
        }
        
        if (ptr->right != 0)
        {
            dfs(ptr->right, treeVect);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> result;
        
        dfs(root1, result);
        dfs(root2, result);
        
        sort(result.begin(), result.end());
      
        return result;
    }
};
