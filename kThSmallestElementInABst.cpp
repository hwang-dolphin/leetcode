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
    static void dfs(TreeNode * & node, set<int> & mySet)
    {
        mySet.insert(node->val);
        
        if (node->left == 0 && node->right == 0)
        {
            return;
        }
        
        else
        {
            if (node->left != 0)
            {
                dfs(node->left, mySet);
            }
            
            if (node->right != 0)
            {
                dfs(node->right, mySet);
            }
        }
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int result;
        
        set<int> mySet;
        set<int>::iterator mySetIte;
        
        dfs(root, mySet);
        
        result = (*mySet.begin() + k - 1);
        
        return result;
    }
};
