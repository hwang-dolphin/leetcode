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

    static void dfs(TreeNode* & node, set<int> & mySet)
    {
        mySet.insert(node->val);
        
        if (node->left == 0 && node->right == 0)
        {
            return;
        }
        
        else
        {
            dfs(node->left, mySet);
            dfs(node->right, mySet);
        }
        
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        int answer;
        set<int> mySet;
        dfs(root, mySet);
        
        if (mySet.size() <= 1)
        {
            answer = -1;
        }
        
        else
        {
            mySet.erase(*mySet.begin());
            answer = *mySet.begin();
        }
        
        return answer;
    }
};
