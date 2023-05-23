#include<iostream>

using namespace std;

//结构体
#define MaxSize 10 //定义栈中元素的最大个数
typedef struct
{
	int data[MaxSize];//静态数组存放栈中元素
	int top;//栈顶指针
} SqStack;

//共享栈
typedef struct
{
	int data[MaxSize]; //静态数组存放栈中元素
	int top0; //0号栈栈顶指针
	int top1; //1号栈栈顶指针
} ShStack;

//初始化共享栈
void InitStack(ShStack& S)
{
	S.top0 = -1;
	S.top1 = MaxSize; 
	//栈满条件为top0+1==top1
}

//初始化
void InitStack(SqStack& S)
{
	S.top = -1;//初始化栈顶指针 若为0.则指向下一个插入的位置
}

//判空
bool StackEmpty(SqStack S)
{
	if (S.top == -1) return true;//判空
	else return false;
}

//进栈
bool Push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)//栈满，报错
		return false;
	S.top = S.top + 1;//先加1
	S.data[S.top] = x;//新元素入栈 这两行等价于S.data[++S.top]=x;
	return true;
}

//出栈
bool Pop(SqStack& S, int& x)
{
	if (S.top == -1) return false;//栈空，报错
	x = S.data[S.top];//栈顶元素先出栈
	S.top = S.top - 1;//指针再减一 这两行等价于 x=S.data[S.top--]
	return true;
}

//读取栈顶元素
bool GetTop(SqStack& S, int& x)
{
	if (S.top == -1) return false;//栈空，报错
	x = S.data[S.top];//栈顶元素出栈
	return true;
}

//使用
void testStack()
{
	SqStack S;//声明一个顺序栈（分配空间）
}
