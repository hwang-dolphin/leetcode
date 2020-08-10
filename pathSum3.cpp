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
Intuition:  DFS using a vector of integers to help.  Each time about to back track, traverse the vector 
            looking for any subsums equal to "sum".  When finished looping, remove the last integer from 
	    vector and backtrack.  Keep DFS until is time to back track, when backtracking, again
            traverse the vector variable from last to first looking for any subsum equal to sum. Then remove the
	    last element from vector and back track.

RunTime Complexity: O(N)
Space Complexity: O(N)
*/


class Solution 
{
private: 
    vector<int> listVect;
    int result = 0;
    
public:

  void dfs2(TreeNode* & ptr, int sum)
    {
        if (ptr == 0)
        {
            return;
        }
        
        listVect.push_back(ptr->val);
        
        dfs(ptr->left, sum);
        dfs(ptr->right, sum);
        
        int temp = 0;
        
        for (int i = listVect.size() - 1; i >= 0; i--)
        {
            temp += listVect[i];
            if (temp == sum)
            {
                result++;
            }
        }
        
        listVect.pop_back();
    }


    
    void dfs(TreeNode* & ptr, int sum)
    {
        listVect.push_back(ptr->val);
        
        if (ptr->left == 0 && ptr->right == 0)
        {
            int temp = 0;
        
            for (int i = listVect.size() - 1; i >= 0; i--)
            {
                temp += listVect[i];
                if (temp == sum)
                {
                    result++;
                }
            }
        
            listVect.pop_back();
            
            return;
        }
        
        if (ptr->left != 0)
        {
            dfs(ptr->left, sum);
        }
        
        if (ptr->right != 0)
        {
            dfs(ptr->right, sum);
        }
        
        int temp = 0;
        
        for (int i = listVect.size() - 1; i >= 0; i--)
        {
            temp += listVect[i];
            if (temp == sum)
            {
                result++;
            }
        }
        
        listVect.pop_back();
    }
    
    int pathSum(TreeNode* root, int sum) 
    {
        if (root == 0)
        {
            return 0;
        }
       
        dfs(root, sum);
        
        return result;
    }
};
