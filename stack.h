#pragma once
extern struct BinTreeNode;
typedef struct BinTreeNode* pData;
#define DataType pData
//动态栈
typedef struct stack {
	DataType *array;
	int top;
	int capacity;
}Stack;

void init(Stack *s);//初始化
void pushBack(Stack *s, DataType data);//入栈
void pop(Stack *s);//出栈
DataType top(Stack *s);//获取栈顶元素
int  checkCapacity(Stack *s);//检查容量，扩容
void destory(Stack* s);//销毁栈   
int isEmpty(Stack* s);//判空
int stackSize(Stack * s);//获取栈元素个数
void printStack(Stack * min);//从底到顶打印栈