#include "BinTree.h"
#include <string.h>
int main()
{
	pBTNode pRoot;
	const char *str = "ABD###CE##F";
	CreateBinTree(&pRoot, str, strlen(str), '#');
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");
	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");
	printf("后序遍历：");
	PostOrder(pRoot);
	printf("\n");
	pBTNode pCopy = CopyBinTree(pRoot);
	printf("复制树  ：");
	PreOrder(pCopy);
	printf("\n");
	DestroyBinTree(&pCopy);
	printf("层序遍历：");
	LevelOrder(pRoot);
	printf("\n");
	printf("非递归先序遍历一：");
	PreOrderNor(pRoot);
	printf("\n");
	printf("非递归先序遍历二：");
	PreOrderNorOP(pRoot);
	printf("\n");
	printf("镜像树（递归）：");
	MirrorBinTree(pRoot);
	PreOrderNor(pRoot);
	printf("\n");
	printf("镜像树（非递归）：");
	MirrorBinTreeNor(pRoot);
	PreOrderNor(pRoot);
	printf("\n");
	printf("结点的个数：%d", BinTreeSize(pRoot));

	printf("\n");
	printf("叶子结点的个数：%d", GetLeafCount(pRoot));

	printf("\n");
	printf("%d层结点的个数：%d",3, GetKLevelNode(pRoot, 3));

	printf("\n");
	printf("二叉树的高度：%d", Height(pRoot));


}