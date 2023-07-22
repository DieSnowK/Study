#include "BinaryTree.h"

BTNode* CreateBinaryTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//递归思想
void PreOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PreOrder(root->left);
	printf("%d ", root->data);
	PreOrder(root->right);
}

void PostOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//计数器的形式
int count = 0;
void TreeSize1(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return;
	}

	count++;
	TreeSize1(root->left);
	TreeSize1(root->right);
}

int TreeSize2(BTNode* root)
{
	assert(root);
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//求K层节点数量
int TreeKLevel(BTNode* root, int k)
{
	//转换成子问题
	//求左子树的第k-1层 + 求右子树的第k-1层
	assert(root);
	assert(k >= 1);

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

//求二叉树深度 - 后序
int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}

	return NULL;
}