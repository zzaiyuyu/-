#pragma once
typedef char BTDataType; 
typedef struct BinTreeNode 
{ 
struct BinTreeNode* _pLeft; 
struct BinTreeNode* _pRight; 
BTDataType _data; 
}BTNode, *pBTNode; 

// 构建二叉树的结点 
pBTNode BuyBinTreeNode(BTDataType data);

// 创建二叉树 
void _CreateBinTree(pBTNode* pRoot, const BTDataType* array, int size, int* index, BTDataType invalid); 
void CreateBinTree(pBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid); 

// 拷贝二叉树 
pBTNode CopyBinTree(pBTNode pRoot); 

// 销毁二叉树 
void DestroyBinTree(pBTNode *pRoot); 

// 前序遍历递归 
void PreOrder(pBTNode pRoot); 
// 前序遍历非递归 一
void PreOrderNor(pBTNode pRoot); 
// 前序遍历非递归 二
void PreOrderNorOP(pBTNode pRoot);

// 中序遍历递归 
void InOrder(pBTNode pRoot); 

// 后续遍历递归 
void PostOrder(pBTNode pRoot); 

// 层序遍历 
void LevelOrder(pBTNode pRoot); 

// 二叉树的镜像递归 
void MirrorBinTree(pBTNode pRoot); 

// 二叉树的镜像非递归 
void MirrorBinTreeNor(pBTNode pRoot); 

// 求二叉树中结点的个数 
int BinTreeSize(pBTNode pRoot); 

// 获取二叉树中叶子结点的个数 
int GetLeafCount(pBTNode pRoot); 

// 求二叉树中K层结点的个数 
int GetKLevelNode(pBTNode pRoot, int K); 

// 求二叉树的高度 
int Height(pBTNode pRoot); 