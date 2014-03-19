/*
 *作者：RogerKing
 *邮箱: jin_tengfei@163.com
 *日期：2014-03-19-10.15
 */

#include <iostream>

using namespace std;

typedef struct TreeNode{
	int key;
	TreeNode*left;//左孩子
	TreeNode*right;//右孩子
	TreeNode*pre;//指向父节点的指针
}*TreePoint;

/*************12.1二叉搜索树*****************************/
//递归的中序遍历
void Inorder_Tree_Walk(TreePoint x)
{
	if (x!=NULL)
	{
		//中序遍历当前结点的左子树
		Inorder_Tree_Walk(x->left);
		//访问当前结点
		cout<<x->key<<" ";
		//中序遍历当前结点的右子树
		Inorder_Tree_Walk(x->right);
	}
}
/*************12.2查询二叉搜索树*************************/
//递归查询二叉搜索树
TreePoint Tree_Search(TreePoint x,int k)
{
	//找到叶子结点了还没找到，或当前结点是所查找的结点
	if(x==NULL||x->key==k)
		return x;
	//所查找的结点位于当前结点的左子树
	if (k<x->key)
		return Tree_Search(x=x->left,k);
	//所查找的结点位于当前结点的左子树
	else
		return Tree_Search(x=x->right,k);
}
//非递归查询二叉搜索树
TreePoint Iterative_Tree_Search(TreePoint x,int k)
{
	//不是叶子结点且不是所查找的结点
    while (x!=NULL&&x->key!=k)
    {
		//所查找的结点位于当前结点的左子树
        if (k<x->key)
			x=x->left;
        //所查找的结点位于当前结点的右子树
		else
            x=x->right;
    }
    return x;
}
//查找树中最小元素
TreePoint Tree_Minimum(TreePoint x)
{
	while (x->left)
	{
		x=x->left;
	}
	return x;
}
//查找树中最大元素
TreePoint Tree_Maximum(TreePoint x)
{
	while (x->right)
	{
		x=x->right;
	}
	return x;
}
//查找某个节点中序遍历情况下的后继节点，后继是大于key[x]的最小的结点
TreePoint Tree_SUCCESSOR(TreePoint x)
{
	if(x == NULL)
    {
        return NULL;
    }
	//如果右子树不为空，则后继为其右子树的最小值节点
	else if (x->right!=NULL)
	{
		return Tree_Minimum(x->right);
	}
	TreePoint y=x->pre;
	while (y!=NULL&&x==y->right)
	{
		x=y;
		y=y->pre;
	}
	return y;
}
//查找某个节点中序遍历情况下的前驱节点，前驱是小于key[x]的最大的结点 。
TreePoint Tree_Predecessor(TreePoint x)
{
    if(x == NULL)
    {
        return NULL;
    }
	//如果左子树不为空，则前驱为其左子树的最大值节点
    else if(x->left != NULL)
    {
        return Tree_Maximum(x->left);
    }
    TreePoint t=x->pre;
    while((t != NULL) && (x == t->left))
    {
		x = t;
		t = t->pre;
	}
	return t;
}
/*************12.3插入和删除*****************************/
//采用循环而非递归的插入树节点。
void Tree_Insert(TreePoint& T,int key)
{
	TreePoint x=T,y=NULL,
	z = new TreeNode;
	z->key=key;
	z->left=z->right=z->pre=NULL;
	//树中有节点时找到插入节点需要插入的位置
	while (x!=NULL)
	{
		y=x;
		if (key<x->key)
		{
			x=x->left;
		}
		else
			x=x->right;
	}
	z->pre=y;
	if (y==NULL)//树为空时
	{
		T=z;
	}
	else
	{
		if (key<y->key)
		{
			y->left=z;
		}
		else
		{
			y->right=z;
		}
	}
}

//二叉搜索树的删除
void Tree_Delete(TreePoint root,TreePoint z)
{
	TreePoint x=NULL,y;
	//若z最多只有一个孩子，实际删除的结点是z
	if (z->left==NULL||z->right==NULL)
		y=z;
	//若z有两个孩子，实际删除的结点是z的后继
	else
		y=Tree_SUCCESSOR(z);
	//用x表示"实际要删除的结点"的孩子（最多一个孩子）
	if (y->left!=NULL)
		x=y->left;
	else
		x=y->right;
	//修改指针，以删去结点
	if (x!=NULL)//若"实际要删除的结点"没有孩子
		x->pre=y->pre;
	if (y->pre==NULL)//若"实际要删除的结点"是根结点
		root=x;
	else if (y==y->pre->left)
		     y->pre->left=x;
	    else
		     y->pre->right=x;
	//"若初阶要删除的结点"不是"待删除的结点"，则内容替代
	if (y!=z)
		z->key=y->key;
}
int main()
{
	TreePoint root=NULL;
	int a[14]={15,5,26,35,2,20,17,3,18,24,6,1,10,7};
	for (int i=0;i<14;i++)
	{
		Tree_Insert(root,a[i]);
	}
	cout<<"中序遍历树结果\n";
	Inorder_Tree_Walk(root);
	cout<<endl;
	cout<<"插入元素：19 ";
	Tree_Insert(root,19);
	cout<<endl;
	cout<<"插入元素后中序遍历树结果\n";
	Inorder_Tree_Walk(root);
	cout<<endl;
	cout<<"查找元素15：";
	TreePoint p=Tree_Search(root,15);
	if (p)
	{
		cout<<"已经找到元素 \n";
	}
	else
		cout<<"没有找到元素 \n";
	cout<<"元素15的前驱节点:";
	cout<<	Tree_Predecessor(p)->key<<" "<<(Tree_Predecessor(p) != NULL ? "查找成功" : "查找失败")<<endl;
	p=Tree_Search(root,20);
	cout<<"元素20的后继节点:";
	cout<<Tree_SUCCESSOR(p)->key<<" "<<(Tree_SUCCESSOR(p) != NULL ? "查找成功" : "查找失败")<<endl;
	cout<<"删除树中值为10的元素\n";
	p=Tree_Search(root,10);
	Tree_Delete(root,p);
	Inorder_Tree_Walk(root);
	cout<<endl;
	return 0;
}
