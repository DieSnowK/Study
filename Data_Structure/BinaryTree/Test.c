#include "BinaryTree.h"

//�˴��ֶ����ٴ���һ�ü򵥵Ķ�����,����ѧϰ
//�����Ƕ�������������ȷ��ʽ
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

int main()
{
	BTNode* root = CreatBinaryTree();

	return 0;
}