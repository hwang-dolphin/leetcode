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
    
    void dfs(TreeNode * ptr, vector<int> & myVect)
    {
        myVect.push_back(ptr->val);
        
        if (ptr->left == 0 && ptr->right == 0)
        {
            return;
        }
        
        else
        {
            if (ptr->left != 0)
            {
                dfs(ptr->left, myVect);
            }
            
            else if (ptr->left == 0)
            {
                myVect.push_back(-1);
            }
            
            if (ptr->right != 0)
            {
                dfs(ptr->right, myVect);
            }
            
            else if (ptr->right == 0)
            {
                myVect.push_back(-1);
            }
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int> pTreeVect;
        vector<int> qTreeVect;
        
        if (p == 0 && q == 0)
        {
            return true;
        }
        
        if ((p == 0 && q != 0) || (p != 0 && q == 0))
        {
            return false;
        }
        
        dfs(p, pTreeVect);
        dfs(q, qTreeVect);
        
        return (pTreeVect == qTreeVect) ? true : false;
    }
};
