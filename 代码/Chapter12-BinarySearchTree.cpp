/*
 *���ߣ�RogerKing
 *����: jin_tengfei@163.com
 *���ڣ�2014-03-19-10.15
 */

#include <iostream>

using namespace std;

typedef struct TreeNode{
	int key;
	TreeNode*left;//����
	TreeNode*right;//�Һ���
	TreeNode*pre;//ָ�򸸽ڵ��ָ��
}*TreePoint;

/*************12.1����������*****************************/
//�ݹ���������
void Inorder_Tree_Walk(TreePoint x)
{
	if (x!=NULL)
	{
		//���������ǰ����������
		Inorder_Tree_Walk(x->left);
		//���ʵ�ǰ���
		cout<<x->key<<" ";
		//���������ǰ����������
		Inorder_Tree_Walk(x->right);
	}
}
/*************12.2��ѯ����������*************************/
//�ݹ��ѯ����������
TreePoint Tree_Search(TreePoint x,int k)
{
	//�ҵ�Ҷ�ӽ���˻�û�ҵ�����ǰ����������ҵĽ��
	if(x==NULL||x->key==k)
		return x;
	//�����ҵĽ��λ�ڵ�ǰ����������
	if (k<x->key)
		return Tree_Search(x=x->left,k);
	//�����ҵĽ��λ�ڵ�ǰ����������
	else
		return Tree_Search(x=x->right,k);
}
//�ǵݹ��ѯ����������
TreePoint Iterative_Tree_Search(TreePoint x,int k)
{
	//����Ҷ�ӽ���Ҳ��������ҵĽ��
    while (x!=NULL&&x->key!=k)
    {
		//�����ҵĽ��λ�ڵ�ǰ����������
        if (k<x->key)
			x=x->left;
        //�����ҵĽ��λ�ڵ�ǰ����������
		else
            x=x->right;
    }
    return x;
}
//����������СԪ��
TreePoint Tree_Minimum(TreePoint x)
{
	while (x->left)
	{
		x=x->left;
	}
	return x;
}
//�����������Ԫ��
TreePoint Tree_Maximum(TreePoint x)
{
	while (x->right)
	{
		x=x->right;
	}
	return x;
}
//����ĳ���ڵ������������µĺ�̽ڵ㣬����Ǵ���key[x]����С�Ľ��
TreePoint Tree_SUCCESSOR(TreePoint x)
{
	if(x == NULL)
    {
        return NULL;
    }
	//�����������Ϊ�գ�����Ϊ������������Сֵ�ڵ�
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
//����ĳ���ڵ������������µ�ǰ���ڵ㣬ǰ����С��key[x]�����Ľ�� ��
TreePoint Tree_Predecessor(TreePoint x)
{
    if(x == NULL)
    {
        return NULL;
    }
	//�����������Ϊ�գ���ǰ��Ϊ�������������ֵ�ڵ�
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
/*************12.3�����ɾ��*****************************/
//����ѭ�����ǵݹ�Ĳ������ڵ㡣
void Tree_Insert(TreePoint& T,int key)
{
	TreePoint x=T,y=NULL,
	z = new TreeNode;
	z->key=key;
	z->left=z->right=z->pre=NULL;
	//�����нڵ�ʱ�ҵ�����ڵ���Ҫ�����λ��
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
	if (y==NULL)//��Ϊ��ʱ
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

//������������ɾ��
void Tree_Delete(TreePoint root,TreePoint z)
{
	TreePoint x=NULL,y;
	//��z���ֻ��һ�����ӣ�ʵ��ɾ���Ľ����z
	if (z->left==NULL||z->right==NULL)
		y=z;
	//��z���������ӣ�ʵ��ɾ���Ľ����z�ĺ��
	else
		y=Tree_SUCCESSOR(z);
	//��x��ʾ"ʵ��Ҫɾ���Ľ��"�ĺ��ӣ����һ�����ӣ�
	if (y->left!=NULL)
		x=y->left;
	else
		x=y->right;
	//�޸�ָ�룬��ɾȥ���
	if (x!=NULL)//��"ʵ��Ҫɾ���Ľ��"û�к���
		x->pre=y->pre;
	if (y->pre==NULL)//��"ʵ��Ҫɾ���Ľ��"�Ǹ����
		root=x;
	else if (y==y->pre->left)
		     y->pre->left=x;
	    else
		     y->pre->right=x;
	//"������Ҫɾ���Ľ��"����"��ɾ���Ľ��"�����������
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
	cout<<"������������\n";
	Inorder_Tree_Walk(root);
	cout<<endl;
	cout<<"����Ԫ�أ�19 ";
	Tree_Insert(root,19);
	cout<<endl;
	cout<<"����Ԫ�غ�������������\n";
	Inorder_Tree_Walk(root);
	cout<<endl;
	cout<<"����Ԫ��15��";
	TreePoint p=Tree_Search(root,15);
	if (p)
	{
		cout<<"�Ѿ��ҵ�Ԫ�� \n";
	}
	else
		cout<<"û���ҵ�Ԫ�� \n";
	cout<<"Ԫ��15��ǰ���ڵ�:";
	cout<<	Tree_Predecessor(p)->key<<" "<<(Tree_Predecessor(p) != NULL ? "���ҳɹ�" : "����ʧ��")<<endl;
	p=Tree_Search(root,20);
	cout<<"Ԫ��20�ĺ�̽ڵ�:";
	cout<<Tree_SUCCESSOR(p)->key<<" "<<(Tree_SUCCESSOR(p) != NULL ? "���ҳɹ�" : "����ʧ��")<<endl;
	cout<<"ɾ������ֵΪ10��Ԫ��\n";
	p=Tree_Search(root,10);
	Tree_Delete(root,p);
	Inorder_Tree_Walk(root);
	cout<<endl;
	return 0;
}
