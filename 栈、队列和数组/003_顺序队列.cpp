#include<iostream>

using namespace std;

#define MaxSize 10 //定义队列中元素的最大个数
typedef struct
{
	int data[MaxSize];//用静态数组存放队列元素、
	int front, rear;//队头指针和队尾指针
} SqQueue;

//初始化队列
void InitQueue(SqQueue& Q)
{
	//初始，队头队尾指针指向0
	Q.front = Q.rear = 0;//队尾指针始终指向下一个插入的位置
}

//判空
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear == Q.front) return true;
	else return false;
}

//实例化
void testQueue()
{
	SqQueue Q;
	InitQueue(Q);
}

//入队
bool EnQueue(SqQueue& Q, int x)
{
	if ((Q.rear+1)%MaxSize==Q.front)//判断队满
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1)%MaxSize;//队尾指针加1取模，以循环队列的形式进行存储
}

//出队
bool DeQueue(SqQueue& Q, int& x)
{
	if (Q.rear == Q.front)//判空
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;//队头后移
	return true;
}

//获取队头元素
bool GetHead(SqQueue& Q, int& x)
{
	if (Q.rear == Q.front)//判空
		return false;
	x = Q.data[Q.front];
	return true;
}

int main()
{
	return 0;
}