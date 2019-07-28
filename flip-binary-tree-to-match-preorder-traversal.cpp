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
    vector <int> flipped;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int index = 0;
        dfs( root, voyage, index );
        return flipped;
    }
    void dfs( TreeNode * node, vector <int> & v, int & index )
    {
        if( node != NULL )
        {
            if( index >= v.size() ) return;
            if( node->val != v[index++] )
            {
                flipped.clear();
                flipped.push_back(-1);
                return;
            }
            else
            {
                if( index < v.size() && node->left != NULL && node->left->val != v[index] )
                {
                    flipped.push_back(node->val);
                    dfs(node->right,v,index);
                    dfs(node->left,v,index);
                }
                else
                {
                    dfs(node->left,v,index);
                    dfs(node->right,v,index);
                }
            }
        }
    }
};
