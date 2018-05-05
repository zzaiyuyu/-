#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "BinTree.h"
#include "queue.h"
#include "stack.h"
// 构建二叉树的结点 
pBTNode BuyBinTreeNode(BTDataType data)
{
	pBTNode pNew = (pBTNode)malloc(sizeof(BTNode));
	if (NULL == pNew) {
		printf("失败");
		return NULL;
	}
	pNew->_data = data;
	pNew->_pLeft = pNew->_pRight = NULL;
	return pNew;
}

// 创建二叉树 
void _CreateBinTree(pBTNode* pRoot, const BTDataType* array, int size, int* index, BTDataType invalid)
{
	if (*index < size && array[*index]!= invalid) {
		*pRoot = BuyBinTreeNode(array[*index]);
		*index += 1;
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);
		*index += 1;
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);
	}
}
void CreateBinTree(pBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid)
{
	assert(pRoot);
	assert(array);
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

// 拷贝二叉树 
pBTNode CopyBinTree(pBTNode pRoot)
{
	pBTNode pNew = NULL;
	if (pRoot) {
		pNew = BuyBinTreeNode(pRoot->_data);
		pNew->_pLeft = CopyBinTree(pRoot->_pLeft);
		pNew->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNew;
}

// 销毁二叉树 
void DestroyBinTree(pBTNode *pRoot)
{
	if (*pRoot) {
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

// 前序遍历递归 
void PreOrder(pBTNode pRoot)
{
	if (pRoot) {
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
// 前序遍历非递归一
void PreOrderNor(pBTNode pRoot)
{
	Stack s;
	init(&s);
	pushBack(&s, pRoot);
	while (!isEmpty(&s)) {
		pBTNode pCur = top(&s);
		pop(&s);
		printf("%c ", pCur->_data);
		if (pCur->_pRight)
			pushBack(&s, pCur->_pRight);
		if (pCur->_pLeft)
			pushBack(&s, pCur->_pLeft);
	}
}
// 前序遍历非递归二
void PreOrderNorOP(pBTNode pRoot)
{
	Stack s;
	init(&s);
	pushBack(&s, pRoot);
	while (!isEmpty(&s)) {
		pBTNode pCur = top(&s);
		pop(&s);
		while (pCur) {
			printf("%c ", pCur->_data);
			if (pCur->_pRight) {
				pushBack(&s, pCur->_pRight);
			}
			pCur = pCur->_pLeft;
		}
	}
}

// 中序遍历递归 
void InOrder(pBTNode pRoot)
{
	if (pRoot) {
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// 后续遍历递归 
void PostOrder(pBTNode pRoot)
{
	if (pRoot) {
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// 层序遍历 
void LevelOrder(pBTNode pRoot)
{
	LQueue q;
	InitQueue(&q);
	PushQueue(&q, pRoot);
	while (!QueueEmpyt(&q)) {
		pBTNode pCur = QueueFront(&q);
		PopQueue(&q);
		printf("%c ", pCur->_data);
		if(pCur->_pLeft)
			PushQueue(&q, pCur->_pLeft);
		if (pCur->_pRight)
			PushQueue(&q, pCur->_pRight);
	}
}

void swap(pBTNode *left, pBTNode *right)
{
	pBTNode tmp = *left;
	*left = *right;
	*right = tmp;
}
// 二叉树的镜像递归 
void MirrorBinTree(pBTNode pRoot)
{
	if (pRoot) {
		swap(&pRoot->_pLeft, &pRoot->_pRight);
		MirrorBinTree(pRoot->_pLeft);
		MirrorBinTree(pRoot->_pRight);
	}
}

// 二叉树的镜像非递归 
void MirrorBinTreeNor(pBTNode pRoot)
{
	LQueue q;
	InitQueue(&q);
	PushQueue(&q, pRoot);
	while (!QueueEmpyt(&q)) {
		pBTNode pCur = QueueFront(&q);
		PopQueue(&q);
		if (pCur->_pLeft)
			PushQueue(&q, pCur->_pLeft);
		if (pCur->_pRight)
			PushQueue(&q, pCur->_pRight);
		swap(&pCur->_pLeft, &pCur->_pRight);
	}
}

// 求二叉树中结点的个数 
int BinTreeSize(pBTNode pRoot)
{
	if (NULL == pRoot) {
		return 0;
	}
	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}

// 获取二叉树中叶子结点的个数 
int GetLeafCount(pBTNode pRoot)
{
	if (NULL == pRoot) {
		return 0;
	}
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight) {
		return 1;
	}
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

// 求二叉树中K层结点的个数 
int GetKLevelNode(pBTNode pRoot, int K)
{
	if (NULL == pRoot || K < 0) {
		return 0;
	}
	if (K == 1) {
		return 1;
	}
	return GetKLevelNode(pRoot->_pLeft, K - 1) + GetKLevelNode(pRoot->_pRight, K - 1);
}

// 求二叉树的高度 
int Height(pBTNode pRoot)
{
	if (NULL == pRoot) {
		return 0;
	}
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	return  left > right ? left + 1 : right + 1;
}