#pragma once
extern struct BinTreeNode;
typedef struct BinTreeNode* pData;
#define DataType pData
//��̬ջ
typedef struct stack {
	DataType *array;
	int top;
	int capacity;
}Stack;

void init(Stack *s);//��ʼ��
void pushBack(Stack *s, DataType data);//��ջ
void pop(Stack *s);//��ջ
DataType top(Stack *s);//��ȡջ��Ԫ��
int  checkCapacity(Stack *s);//�������������
void destory(Stack* s);//����ջ   
int isEmpty(Stack* s);//�п�
int stackSize(Stack * s);//��ȡջԪ�ظ���
void printStack(Stack * min);//�ӵ׵�����ӡջ