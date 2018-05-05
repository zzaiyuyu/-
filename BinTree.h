#pragma once
typedef char BTDataType; 
typedef struct BinTreeNode 
{ 
struct BinTreeNode* _pLeft; 
struct BinTreeNode* _pRight; 
BTDataType _data; 
}BTNode, *pBTNode; 

// �����������Ľ�� 
pBTNode BuyBinTreeNode(BTDataType data);

// ���������� 
void _CreateBinTree(pBTNode* pRoot, const BTDataType* array, int size, int* index, BTDataType invalid); 
void CreateBinTree(pBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid); 

// ���������� 
pBTNode CopyBinTree(pBTNode pRoot); 

// ���ٶ����� 
void DestroyBinTree(pBTNode *pRoot); 

// ǰ������ݹ� 
void PreOrder(pBTNode pRoot); 
// ǰ������ǵݹ� һ
void PreOrderNor(pBTNode pRoot); 
// ǰ������ǵݹ� ��
void PreOrderNorOP(pBTNode pRoot);

// ��������ݹ� 
void InOrder(pBTNode pRoot); 

// ���������ݹ� 
void PostOrder(pBTNode pRoot); 

// ������� 
void LevelOrder(pBTNode pRoot); 

// �������ľ���ݹ� 
void MirrorBinTree(pBTNode pRoot); 

// �������ľ���ǵݹ� 
void MirrorBinTreeNor(pBTNode pRoot); 

// ��������н��ĸ��� 
int BinTreeSize(pBTNode pRoot); 

// ��ȡ��������Ҷ�ӽ��ĸ��� 
int GetLeafCount(pBTNode pRoot); 

// ���������K����ĸ��� 
int GetKLevelNode(pBTNode pRoot, int K); 

// ��������ĸ߶� 
int Height(pBTNode pRoot); 