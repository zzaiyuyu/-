#include "BinTree.h"
#include <string.h>
int main()
{
	pBTNode pRoot;
	const char *str = "ABD###CE##F";
	CreateBinTree(&pRoot, str, strlen(str), '#');
	printf("ǰ�������");
	PreOrder(pRoot);
	printf("\n");
	printf("���������");
	InOrder(pRoot);
	printf("\n");
	printf("���������");
	PostOrder(pRoot);
	printf("\n");
	pBTNode pCopy = CopyBinTree(pRoot);
	printf("������  ��");
	PreOrder(pCopy);
	printf("\n");
	DestroyBinTree(&pCopy);
	printf("���������");
	LevelOrder(pRoot);
	printf("\n");
	printf("�ǵݹ��������һ��");
	PreOrderNor(pRoot);
	printf("\n");
	printf("�ǵݹ������������");
	PreOrderNorOP(pRoot);
	printf("\n");
	printf("���������ݹ飩��");
	MirrorBinTree(pRoot);
	PreOrderNor(pRoot);
	printf("\n");
	printf("���������ǵݹ飩��");
	MirrorBinTreeNor(pRoot);
	PreOrderNor(pRoot);
	printf("\n");
	printf("���ĸ�����%d", BinTreeSize(pRoot));

	printf("\n");
	printf("Ҷ�ӽ��ĸ�����%d", GetLeafCount(pRoot));

	printf("\n");
	printf("%d����ĸ�����%d",3, GetKLevelNode(pRoot, 3));

	printf("\n");
	printf("�������ĸ߶ȣ�%d", Height(pRoot));


}