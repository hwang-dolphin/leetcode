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
 Intuition:
 Front tranverse the tree, Preorder (Root, Left, Right), doing comparisons using the absolute value.
 Use additional variables sent to dfs for tracking purposes;

 RunTime Complexity: O(2^depth) or O(2^log2(n))
 Space Complexity: O(1)
*/

class Solution {
public:
    void dfs(TreeNode* & ptr, double & result, double & tempAnswer, double target)
    {        
        if (abs(ptr->val - target) < tempAnswer)
        {
            tempAnswer = abs(ptr->val - target);
            result = ptr->val;
        }
        
        if (ptr->left == 0 && ptr->right == 0)
        {
            return;
        }
        
        if (ptr->left != 0)
        {
            dfs(ptr->left, result, tempAnswer, target);
        }
        
        if (ptr->right != 0)
        {
            dfs(ptr->right, result, tempAnswer, target);
        }
    }
    
    int closestValue(TreeNode* root, double target) 
    {
        double answer = DBL_MAX;
        double tempAnswer = DBL_MAX;
        
        dfs(root, answer, tempAnswer, target);
        
        return answer;
    }
};
