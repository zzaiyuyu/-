#include "queue.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
qNode * BuyNode(DataType data)
{
	qNode * new = (qNode*)malloc(sizeof(qNode));
	if (NULL == new) {
		printf("分配失败");
		return NULL;
	}
	new->data = data;
	new->next = NULL;
	return new;
}
void InitQueue(LQueue *queue)
{
	assert(queue);
	//创建头结点
	qNode * head= BuyNode(0);
	queue->front = head;
	queue->tail = head;
}
void PushQueue(LQueue *queue, DataType data)
{
	qNode *new = BuyNode(data);
	queue->tail->next = new;
	queue->tail = new;
}
void PopQueue(LQueue * queue)
{
	qNode *pDel = queue->front->next;
	//不是空队列
	if (pDel) {
		//除头结点只有一个结点
		if (NULL == pDel->next) {
			queue->tail = queue->front;
		}
		queue->front->next = pDel->next;
	}
}
DataType QueueFront(LQueue* queue)
{
	if (queue->front->next) {
		return queue->front->next->data;
	}
	return queue->front->data;
}
int QueueSize(LQueue* queue)
{
	int count = 0;
	qNode * pcur = queue->front->next;
	while (pcur) {
		count++;
		pcur = pcur->next;
	}
	return count;
}
int QueueEmpyt(LQueue* queue)
{
	if (queue->front == queue->tail) {
		return 1;
	}
	return 0;
}
void DestoryQueue(LQueue** queue)
{
	if (*queue != NULL) {
		while ((*queue)->front) {
			PopQueue(*queue);
		}
		free(*queue);
		*queue = NULL;
	}

}