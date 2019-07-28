/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector <int> dp;
    vector <int> po;
    void pr( TreeNode * root )
    {
        if( root == NULL ) return ;
        po.push_back(root->val);
        pr(root->left); pr(root->right);
    }
    int dpp( TreeNode * root, int & index )
    {
        int h = index;
        dp[index++] = root->val;
        int a,b; a = b=  0;
        if( root->left ) a = dpp(root->left,index);
        if( root->right ) b = dpp(root->right,index);
        if( a > 0 ) dp[h] += a;
        if( b > 0 ) dp[h] += b;
        return root->val+max(max(a,b),0);
    }
    int maxPathSum(TreeNode* root) {
        pr(root);
        dp.assign(po.size(),-1);
        int index = 0;
        dpp(root,index);
        int ma = dp[0]; for( int i = 1; i < dp.size(); i++ ) ma = max(ma,dp[i]);
        return ma;
    }
};
