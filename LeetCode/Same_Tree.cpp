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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ( p==NULL && q==NULL ) return true;
        else if ( p==NULL || q==NULL ) return false;
        else if (p->val==q->val){
			if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right) )
				return true;
            else return false;
        }
        else return false;
    }
};