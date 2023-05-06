#include<iostream>

using namespace std;

//结构体
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front, * rear;//队头队尾指针
}LinkQueue;

//初始化
void InitQueue(LinkQueue& Q)
{
	//初始时 front、rear都指向头结点
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//判空
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else return false;
}

//入队
void EnQueue(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;//新节点插入到rear后面
	Q.rear = s;//修改表尾指针
}

//出队
bool DeQueue(LinkQueue& Q, int& x)
{
	if (Q.front == Q.rear) return false;//判空
	LinkNode* p = Q.front->next;
	x = p->data;//用变量x返回队头元素
	Q.front->next = p->next;//修改头结点的next指针
	if (Q.rear == p)//此次是最后一个结点出队
		Q.rear = Q.front;//修改rear指针
	free(p);//释放结点空间
	return true;
}

//实例化
void testLinkQueue()
{
	LinkQueue Q;//声明一个队列
	InitQueue(Q);//初始化队列
}

//不带头结点版本
//初始化（不带头结点）
void InitQueue2(LinkQueue& Q)
{
	//初始时，front、rear都指向NULL
	Q.front = NULL;
	Q.rear = NULL;
}
//判空（不带头结点）
bool IsEmpty2(LinkQueue Q)
{
	if (Q.front == NULL) return true;
	else return false;
}
//入队（不带头结点）
void EnQueue2(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)//在空序列中插入第一个元素
	{
		Q.front = s;
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s;
		Q.rear = s;
	}
}
//出队（不带头结点）
bool DeQueue2(LinkQueue& Q, int& x)
{
	if (Q.front == NULL) return false;
	LinkNode* p = Q.front;//p指向此次出队的结点
	x = p->data;//用变量x返回队头元素
	Q.front = p->next;//修改front指针
	if (Q.rear == p)//此次是最后一个结点出队
	{
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);//释放结点
}


int main()
{
	return 0;
}