#pragma once
extern struct BinTreeNode;
typedef struct BinTreeNode* pData;
#define DataType pData
typedef struct Node {
	DataType data;
	struct Node * next;
}qNode;

//基于带头结点的单链表队列
typedef struct Queue {
	qNode * front;
	qNode * tail;
}LQueue;

void InitQueue(LQueue *queue);
void PushQueue(LQueue *queue, DataType data);
void PopQueue(LQueue * queue);
DataType QueueFront(LQueue* queue);
int QueueSize(LQueue* queue);
int QueueEmpyt(LQueue* queue);
void DestoryQueue(LQueue** queue);