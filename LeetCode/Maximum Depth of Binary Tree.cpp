/*
 *Created by RogerKing
 *Email:jin_tengfei@163.com
 */


#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if( root==NULL ) return 0;
        int maxleft = maxDepth( root->left );
        int maxright = maxDepth( root->right );
        return max(maxleft,maxright)+1;
    }
};
